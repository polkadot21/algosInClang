#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int strLen(char strArr[]) {
    char interChar = '\0';
    int counter = 0;
    char current = strArr[counter];
    while (current != interChar) {
        counter ++;
        current = strArr[counter];
    }
    return counter;
}

int isPalindrome(char arr[]) {
    int lenArr = strLen(arr);
    char reversed[lenArr+1];
    for (int i=0;i<lenArr;i++){
        reversed[i] = arr[lenArr-i-1];
    }
    reversed[lenArr] = '\0';

    for (int j=0; j<lenArr; j++) {
        if (reversed[j] != arr[j]){
            return 0;
        }
    }
    return 1;
}


char* reverse(char arr[]) {
    int lenArr = strLen(arr);

    char* reversed = malloc(lenArr+1);
    for (int i=0;i<lenArr;i++){
        reversed[i] = arr[lenArr-i-1];
    }
    reversed[lenArr] = '\0';
    return reversed;
}


char* appendr_char(char arr[], char oneChar) {
    int lenArr = strLen(arr);
    int lenAppendedArr = lenArr + 2;
    char* res = malloc(lenAppendedArr);
    for (int i=0; i<lenArr; i++){
        res[i] = arr[i];
    }
    res[lenArr] = oneChar;
    res[lenArr+1] = '\0';
    return res;
}


char* appendl_char(char arr[], char oneChar) {
    int lenArr = strLen(arr);
    int lenAppendedArr = lenArr + 2;
    char* res = malloc(lenAppendedArr);
    res[0] = oneChar;
    for (int i=1; i<lenArr+1; i++){
        res[i] = arr[i-1];
    }
    res[lenArr+1] = '\0';
    return res;
}

char* delSymbol(char arr[], int idx) {
    int lenArr = strLen(arr);

    char* res = malloc(lenArr);
    int last_filled = 0;
    for (int i=0;i<lenArr;i++) {
        if (i == idx) {
            last_filled++;
        }
        res[i] = arr[last_filled];
        last_filled++;
    }
    res[lenArr] = '\0';
    return res;
}

int isBeginning(const char smallArr[], const char bigArr[]) {
    int lenSmallArr = strLen(smallArr);

    for (int i=0;i<lenSmallArr;i++) {
        if (bigArr[i] != smallArr[i]) {
            return 0;
        }
    }
    return 1;
}


bool isLowerCaseASCII(int charAsInt) {
    const int lowerBound = 97;
    const int upperBound = 122;

    return (charAsInt >= lowerBound && charAsInt <= upperBound);
}


bool isUpperCaseASCII(int charAsInt) {
    const int lowerBound = 65;
    const int upperBound = 90;

    return (charAsInt >= lowerBound && charAsInt <= upperBound);
}


int isLowercase(char arr[]) {

    int len = strLen(arr);
    for (int i=0;i<len;i++) {
        if (!isLowerCaseASCII((int)arr[i])) {
            return 0;
        }
    }
    return 1;
}


char toUpper(int charAsInt) {
    int up = charAsInt - 32;
    return (char)up;
}


char toLower(int charAsInt) {
    int up = charAsInt + 32;
    return (char)up;
}

char* upcase(char arr[]) {
    int len = strLen(arr);
    char* res = malloc(len+1);

    for (int i=0;i<len;i++) {
        if (isLowerCaseASCII((int)arr[i])) {
            res[i] = toUpper((int)arr[i]);
        } else {
            res[i] = arr[i];
        }
    }
    res[len] = '\0';
    return res;
}

char* swapCase(char arr[]) {
    int len = strLen(arr);
    char* res = malloc(len+1);

    for (int i=0;i<len;i++) {
        if (isLowerCaseASCII((int)arr[i])) {
            res[i] = toUpper((int)arr[i]);
        } else if (isUpperCaseASCII((int)arr[i])) {
            res[i] = toLower((int)arr[i]);
        }
        else {
            res[i] = arr[i];
        }
    }

    res[len] = '\0';
    return res;
}

char* dupString(char arr[], int n) {
    int len = strLen(arr);
    int newLen = len*n;
    char* res = malloc(newLen + 1);
    for (int j=0; j<n;j++) {
        for (int i=0; i<=len;i++) {
            res[i + j*len] = arr[i];
        }
    }
    res[newLen] = '\0';
    return res;
}

int isSubstring(const char subArr[], const char bigArr[]) {
    int lenBigArr = strLen(bigArr);
    int lenSubArr = strLen(subArr);

    for (int i=0;i<lenBigArr;i++) {
        int counter = 0;
        for (int j=0;j<lenSubArr;j++) {
            if (subArr[j] == bigArr[i]) {
                i++;
                counter ++;
            }
        }
        if (counter == lenSubArr) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char arr[] = "abcd";
    int res = isSubstring("ad", arr);
    printf("Res: %d", res);
    return 0;
}
