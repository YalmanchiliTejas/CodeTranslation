#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long int ll;
using namespace std;

int main(){
cin.tie(0);
ios::sync_with_stdio(false);
int N;
cin>>N;
vector<int>H(N);
rep(i,N)cin>>H[i];

int max_height=0;
int cnt=0;

rep(i,N){
    if(H[i]>=max_height)cnt++;
    max_height=max(max_height,H[i]);
}
cout<<cnt<<endl;;
//system("pause");
return 0;
}