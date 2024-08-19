#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>


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

    if (lenSubArr == 0) {
        return 1; // An empty substring is always considered a substring
    }

    for (int i = 0; i <= lenBigArr - lenSubArr; i++) {
        int j;
        for (j = 0; j < lenSubArr; j++) {
            if (bigArr[i + j] != subArr[j]) {
                break;
            }
        }
        if (j == lenSubArr) {
            return 1;
        }
    }

    return 0;
}

// Test functions
void test_strLen() {
    assert(strLen("hello") == 5);
    assert(strLen("") == 0);
    assert(strLen("a") == 1);
}

void test_isPalindrome() {
    assert(isPalindrome("madam") == 1);
    assert(isPalindrome("hello") == 0);
    assert(isPalindrome("a") == 1);
    assert(isPalindrome("") == 1);
}

void test_reverse() {
    char* res1 = reverse("hello");
    assert(strcmp(res1, "olleh") == 0);
    free(res1);

    char* res2 = reverse("");
    assert(strcmp(res2, "") == 0);
    free(res2);

    char* res3 = reverse("a");
    assert(strcmp(res3, "a") == 0);
    free(res3);
}

void test_appendr_char() {
    char* res1 = appendr_char("hello", '!');
    assert(strcmp(res1, "hello!") == 0);
    free(res1);

    char* res2 = appendr_char("", 'a');
    assert(strcmp(res2, "a") == 0);
    free(res2);
}

void test_appendl_char() {
    char* res1 = appendl_char("hello", '!');
    assert(strcmp(res1, "!hello") == 0);
    free(res1);

    char* res2 = appendl_char("", 'a');
    assert(strcmp(res2, "a") == 0);
    free(res2);
}

void test_delSymbol() {
    char* res1 = delSymbol("hello", 0);
    assert(strcmp(res1, "ello") == 0);
    free(res1);

    char* res2 = delSymbol("hello", 2);
    assert(strcmp(res2, "helo") == 0);
    free(res2);

    char* res3 = delSymbol("hello", 4);
    assert(strcmp(res3, "hell") == 0);
    free(res3);
}

void test_isBeginning() {
    assert(isBeginning("hell", "hello") == 1);
    assert(isBeginning("hello", "hello") == 1);
    assert(isBeginning("ello", "hello") == 0);
}

void test_isLowerCaseASCII() {
    assert(isLowerCaseASCII('a') == true);
    assert(isLowerCaseASCII('z') == true);
    assert(isLowerCaseASCII('A') == false);
    assert(isLowerCaseASCII('1') == false);
}

void test_isUpperCaseASCII() {
    assert(isUpperCaseASCII('A') == true);
    assert(isUpperCaseASCII('Z') == true);
    assert(isUpperCaseASCII('a') == false);
    assert(isUpperCaseASCII('1') == false);
}

void test_isLowercase() {
    assert(isLowercase("hello") == 1);
    assert(isLowercase("HELLO") == 0);
    assert(isLowercase("Hello") == 0);
    assert(isLowercase("") == 1);
}


void test_upcase() {
    char* res1 = upcase("hello");
    assert(strcmp(res1, "HELLO") == 0);
    free(res1);

    char* res2 = upcase("HELLO");
    assert(strcmp(res2, "HELLO") == 0);
    free(res2);

    char* res3 = upcase("HeLLo");
    assert(strcmp(res3, "HELLO") == 0);
    free(res3);
}

void test_swapCase() {
    char* res1 = swapCase("hello");
    assert(strcmp(res1, "HELLO") == 0);
    free(res1);

    char* res2 = swapCase("HELLO");
    assert(strcmp(res2, "hello") == 0);
    free(res2);

    char* res3 = swapCase("HeLLo");
    assert(strcmp(res3, "hEllO") == 0);
    free(res3);
}

void test_dupString() {
    char* res1 = dupString("ab", 3);
    assert(strcmp(res1, "ababab") == 0);
    free(res1);

    char* res2 = dupString("", 3);
    assert(strcmp(res2, "") == 0);
    free(res2);
}

void test_isSubstring() {
    assert(isSubstring("lo", "hello") == 1);
    assert(isSubstring("hell", "hello") == 1);
    assert(isSubstring("hello", "hello") == 1);
    assert(isSubstring("world", "hello") == 0);
    assert(isSubstring("", "hello") == 1);
    assert(isSubstring("hello", "") == 0);
}

int main() {
    // Run all test cases
    test_strLen();
    test_isPalindrome();
    test_reverse();
    test_appendr_char();
    test_appendl_char();
    test_delSymbol();
    test_isBeginning();
    test_isLowerCaseASCII();
    test_isUpperCaseASCII();
    test_isLowercase();
    test_upcase();
    test_swapCase();
    test_dupString();
    test_isSubstring();

    printf("All tests passed!\n");
    return 0;
}
