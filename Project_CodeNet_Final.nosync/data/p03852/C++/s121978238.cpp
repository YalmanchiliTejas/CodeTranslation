#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long

int main(void)
{
    char c; cin>>c;
    string v = "aeiou";
    if(v.find(c)!=string::npos) cout<<"vowel"<<endl;
    else cout<<"consonant"<<endl;
    return 0;
} 