#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  

// 辅助函数，用于反转字符串中的字符顺序  
void reverse(char* str, int start, int end) {
    char temp;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// 主函数，用于反转字符串中每个单词的顺序  
void reverseWords(char* str) {
    char* token;
    char* context = strdup(str); // 复制原始字符串，以便在不影响原始字符串的情况下进行操作  
    int start = 0;

    // 使用strtok分割字符串  
    token = strtok(context, " ");
    while (token != NULL) {
        int end = start + strlen(token) - 1; // 获取当前单词的结束位置  
        reverse(str, start, end); // 反转当前单词的字符顺序  
        start = end + 1; // 更新下一个单词的起始位置  
        token = strtok(NULL, " "); // 获取下一个单词  
    }

    free(context); // 释放复制的字符串所占用的内存  
}

int main() {
    char str[] = "Hello World!";
    printf("Original string: %s\n", str);
    reverseWords(str);
    printf("Reversed string: %s\n", str);
    return 0;
}