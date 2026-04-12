#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pint;

int main(){
    char c;
    cin>>c;
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') cout<<"vowel"<<endl;
    else cout<<"consonant"<<endl;
    return 0;
}