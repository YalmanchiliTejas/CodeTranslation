//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int find_(int x,vector<int> &v){
    if(v[x]<0) return x;
    v[x]=find_(v[x],v);
    return v[x];
}

int same_(int a,int b,vector<int> &v){
    if(find_(a,v)==find_(b,v)) return 1;
    return 0;
}

void union_(int a,int b,vector<int> &v){
    if(same_(a,b,v)) return;
    int a_p=find_(a,v),b_p=find_(b,v);
    if(a_p>b_p) swap(a_p,b_p);
    v[a_p]+=v[b_p]; v[b_p]=a_p;
}

void print_v(vector<int> v){
    rep(i,v.size()) cout<<v[i]<<" ";
    cout<<endl;
}

int size_(int a,vector<int> &v){
    return -v[find_(a,v)];
}

int main(){
    set<char> q;
    rep(i,3){
        char ch; cin>>ch;
        q.insert(ch);
    }
    cout<<(q.size()==2 ? "Yes" : "No")<<endl;
}