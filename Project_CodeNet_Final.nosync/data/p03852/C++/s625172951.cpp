#include <cstdio>
#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

int main() {
    char c;
    scanf("%c", &c);
    if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') printf("vowel\n");
    else printf("consonant\n");
}