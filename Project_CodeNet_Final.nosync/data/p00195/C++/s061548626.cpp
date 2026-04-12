#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<utility>
#include<set>
#include<complex>
#include<map>
#define vi vector<int>
#define vvi vector<vector<int> >
#define ll long long int
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define ld long double
#define INF 1e9
#define EPS 0.0000000001
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,s,n) for(int i=s;i<n;i++)
#define CC puts("-------ok--------");
#define all(in) in.begin(), in.end()
using namespace std;
typedef pair<int, int> pii;
#define MAX 99999999
int main(){
    pii temp; pii f=pii(0,0);
    pii ans=pii(0,-INF);
    while(cin>>temp.first>>temp.second,temp!=f){
        ans=pii(0,temp.first+temp.second);
        for(int i=1;i<=4;i++){
            cin>>temp.first>>temp.second;
            if(temp.first+temp.second>ans.second){ans.first=i; ans.second=temp.first+temp.second;}
        }
        char u[]={"ABCDE"};
        cout<<u[ans.first]<<" "<<ans.second<<endl;
        }
    
}