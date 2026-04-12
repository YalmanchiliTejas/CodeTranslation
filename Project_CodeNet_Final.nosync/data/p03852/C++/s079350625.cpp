#include<iostream>
#include<cstdio>
#include<map>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
const int maxn = 2e5+7;
int a[maxn];
char s[maxn];
int main()
{
    char c;
    cin >> c;
    if(c == 'a'||c == 'e'||c == 'i'||c == 'o'||c == 'u')
    {
        cout <<"vowel"<<endl;
    }
    else cout << "consonant" << endl;
    return 0;
}
