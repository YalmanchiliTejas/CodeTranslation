#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    // 引数の受け取り
    char A[100];
    scanf("%s",A);
    if (A[0]=='a' || A[0]=='i' || A[0]=='u'|| A[0]=='e'|| A[0]=='o'){
printf("vowel");
    }else{
printf("consonant");
    
    };

    return 0;
}
