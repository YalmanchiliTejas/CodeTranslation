#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define rv(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int M = 120000;
typedef long long ll;
int n,m,k;
char s[20];
bool ok(){
    int a='A'+'A'+'A';
    int b='B'+'B'+'B';
    int c=s[0]+s[1]+s[2];
    if(c==a||c==b) return 0;
    return 1;
}
int main(){
    cin>>s;
    if(ok()) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}