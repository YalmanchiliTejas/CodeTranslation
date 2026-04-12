#define _GLIBCXX_DEBUG
#include<cmath>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> arr;
stack<int> st;
queue<int> qu;
queue<pair<int,int> > qu2;
priority_queue<int> pq;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rep2(i,n) for(int i=1; i<=(int)(n); i++)
typedef set<int> set_t;
typedef set<string> set_g;
typedef complex<double> xy_t;

int P[10010];
void init(int n){
    for(int i=0;i<n;++i)P[i]=i;
}
int root(int a) {
    if(P[a]==a)return a;
    return (P[a]=root(P[a]));
}
bool is_same_set(int a,int b){
    return root(a) == root(b);
}
void unite(int a,int b){
    P[root(a)]=root(b);
}//対グラフ

double dot_product(xy_t a, xy_t b) { return (conj(a)*b).real(); }//内積
double cross_product(xy_t a, xy_t b) { return (conj(a)*b).imag(); }//外積
xy_t projection(xy_t p, xy_t b) { return b*dot_product(p,b)/norm(b); }//投影
//対図形

int main(){
    int n;
    cin >>n;
    int ans =n;
    int h[n];
    rep(i,n){
        cin >> h[i];
        rep(j,i){
            if(h[i]<h[j]){
                ans-=1;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}