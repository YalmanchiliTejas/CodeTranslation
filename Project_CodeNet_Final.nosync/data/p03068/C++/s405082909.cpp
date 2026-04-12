#include<bits/stdc++.h>
typedef long long ll;
#define INF 100000000
#define MOD 100000007
int dx[4]={1,0,-1,0},dy[4]={0,-1,0,1};
using namespace std;
int main(void){
int n,k;
string s;
cin>>n>>s>>k;
char ch=s[k-1];
for(int i=0;i<s.size();i++){
    if(s[i]!=ch){
        s[i]='*';
    }
}
cout<<s<<endl;
   return 0;    
}