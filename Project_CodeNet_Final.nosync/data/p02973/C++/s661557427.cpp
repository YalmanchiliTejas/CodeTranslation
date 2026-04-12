#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define pr pair<int,int>
#define N 100005
#define mod 1000000007
#define INF 2147483647
using namespace std;
int a[N];
bool vis[N];
vector<int>v;
int main() {
	IOS;
    int m,n,cnt=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    v.push_back(a[1]);
    for(int i=2;i<=n;i++){
        if(v.back()>=a[i])v.push_back(a[i]);
        else{
            int l=-1,r=v.size();
            while(l+1<r){
                int mid=l+r>>1;
                if(v[mid]<a[i])r=mid;
                else l=mid;
            }
            v[l+1]=a[i];
        }
        //for(auto i:v)cout<<i<<' ';
        //cout<<'\n';
    }
    cout<<v.size();
	return 0;
}