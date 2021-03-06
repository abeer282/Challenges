#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
/*
Input Format
The first line contains a single string, s.
The second line contains an integer, n.

Constraints
1 <= len(s)<= 100
1 <= n <= 10^12
For 25% of the test cases,n < 10^6 .

Output Format:
Print a single integer denoting the number of letter a's in the first  letters of the infinite string created by repeating  infinitely many times.

*/
long repeatedString(char* s, long n) {//only this function contains my code
    long result = 0;
    int len = 0, i=0;
    while(*(s+i)!='\0'){
        len++;
        if(*(s+i)=='a')
            result ++;
        i++;
    }
    result = result * (n/len);
    i=0;
    while(i < (n%len)){
        if(*(s+i)=='a')
            result ++;
        i++;
    }
    return result;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* n_endptr;
    char* n_str = readline();
    long n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    long result = repeatedString(s, n);

    fprintf(fptr, "%ld\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}
