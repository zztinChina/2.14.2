#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  

// �������������ڷ�ת�ַ����е��ַ�˳��  
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

// �����������ڷ�ת�ַ�����ÿ�����ʵ�˳��  
void reverseWords(char* str) {
    char* token;
    char* context = strdup(str); // ����ԭʼ�ַ������Ա��ڲ�Ӱ��ԭʼ�ַ���������½��в���  
    int start = 0;

    // ʹ��strtok�ָ��ַ���  
    token = strtok(context, " ");
    while (token != NULL) {
        int end = start + strlen(token) - 1; // ��ȡ��ǰ���ʵĽ���λ��  
        reverse(str, start, end); // ��ת��ǰ���ʵ��ַ�˳��  
        start = end + 1; // ������һ�����ʵ���ʼλ��  
        token = strtok(NULL, " "); // ��ȡ��һ������  
    }

    free(context); // �ͷŸ��Ƶ��ַ�����ռ�õ��ڴ�  
}

int main() {
    char str[] = "Hello World!";
    printf("Original string: %s\n", str);
    reverseWords(str);
    printf("Reversed string: %s\n", str);
    return 0;
}