#include <fstream>
#include <iostream>
#include <ctime>
#include<bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define pb push_back
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d\n",x)
#define s(x) scanf("%lld",&x)
#define p(x) printf("%lld\n",x)
#define sc(x) scanf("%s",x)
#define pc(x) printf("%s",x)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define M 1000000007
#define N 200002
#define inf 1e9
#define PQG priority_queue< int,std::vector<int>,std::greater<int> >
#define PQL priority_queue< int,std::vector<int>,std::less<int> >
#define PQPL priority_queue<pii ,vector< pii >, less< pii > >
#define PQPG priority_queue<pii ,vector< pii >, greater< pii > >

using namespace std;


int main(){
int n;
cin>>n;
int cnt[26];
for(int i=0;i<26;i++) cnt[i]=inf;

for(int i=0;i<n;i++){
    string s;cin>>s;
    int temp[26];
    memset(temp,0,sizeof(temp));
    for(int j=0;j<s.size();j++){
        temp[s[j]-'a']++;
    }
    for(int j=0;j<26;j++){
        cnt[j]=min(cnt[j],temp[j]);
    }
}

string ans="";
for(char i='a';i<='z';i++){
    for(int j=0;j<cnt[i-'a'];j++) ans=ans+i;
}
cout<<ans<<endl;

return 0;
}
