#include<cstdio>
#include<cmath>
#include<string>
#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<map>
#include<set>
#include<limits>
#include<bitset>
#include<array>
#include<numeric>
#include<iomanip>
#include<functional>
#include<deque>

using namespace std;
typedef long long int ll;

#define C cout<<
#define E <<endl

ll n,m,a,b,c,x,y,z,aa[10010][10010];
bool r,ra,rb,rc;
string s,sa,sb,sc[100];
char ca,cb,cc,cd[1000][1000];
vector<ll> va,vb,vc;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>sc[i];
        for(int j=0;j<sc[i].size();j++){
            aa[i][sc[i][j]]++;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<200;j++){
            aa[0][j]=min(aa[0][j],aa[i][j]);
        }
    }
    for(int i=70;i<200;i++){
        for(int j=0;j<aa[0][i];j++)C char(i);
    }
    cout<<endl;
    
}