//Given a string, s, consisting of alphabets and digits, find the frequency of each digit in the given string.
//length of s <= 1000
//example:
//input:a11472o5t6
//output: 0 2 1 0 1 1 1 1 0 0 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char s[1000];
    int counters[10]={0};
    int i;
    scanf("%s",s);
    while(s[i]!='\0'){
        if( s[i] >= '0' && s[i] <= '9' )
            counters[s[i]-'0']++;
        i++;
    }
    for(i=0;i<10;i++)
        printf("%d ",counters[i]);
    return 0;
}