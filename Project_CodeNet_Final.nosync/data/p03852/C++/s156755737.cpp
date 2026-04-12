#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

int main()
{
    char c;
    cin >> c;
    char ans[100];
    if(c=='a' || c=='i' || c=='u' || c=='e' || c=='o'){
        strcpy(ans, "vowel");
    }else{
        strcpy(ans, "consonant");
    }
    cout << ans << endl;
    return 0;
}
