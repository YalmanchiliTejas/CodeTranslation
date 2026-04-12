#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(c) (c).begin(),(c).end()
#define soao(c) sort((c).begin(),(c).end()) //昇順
#define sodo(c) sort((c).begin(),(c).end(),gi()) //降順
#define rev(c) reverse((c).begin(), (c).end())
#define pb(c) push_back(c)
using vi=vector<int>;  using vs=vector<string>; using vc=vector<char>;
using vvi=vector<vector<int>>; using vb=vector<bool>;
using vvs=vector<vector<string>>;
using vvc=vector<vector<char>>;
using gi=greater<int>; 

int main() {
	int h,w; cin>>h>>w;
	vs table(h); rep(i,h) cin>>table.at(i);

	vb row(h, false),col(w, false);
    rep(i,h){
        rep(j,w){
            if(table.at(i).at(j)=='#'){
                row.at(i)=true;
                col.at(j)=true;
            }
        }
    }
    rep(i,h){
        if(row.at(i)){
            rep(j,w){
                if(col.at(j)) cout<<table.at(i).at(j);
            }
            cout<<endl;
        }
    }
}
