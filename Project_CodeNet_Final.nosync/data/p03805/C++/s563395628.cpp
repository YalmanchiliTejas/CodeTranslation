#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG
#define str(n) to_string(n)
#define int(w) stoi(w)
#define len(l) l.size()
#define append(l,i) l.push_back(i)
void dfs(int s,vector<int> prev,int &count,vector<vector<int>> &g){
    for (int x :g.at(s)){
        if (prev.at(x-1)==1){
            continue;
        }
        else{
            prev.at(x-1)=1;

            int b=1;
            rep(i,prev.size()){
                if (prev.at(i)==0){
                    b=0;
                }
            }
            if (b==0){
                dfs(x,prev,count,g);
                prev.at(x-1)=0;
            }
            else{
                count+=1;
            }
            
        }
    }
}
int main() {
    vector<vector<int>> g;
    int n,m;
    cin>>n>>m;
    rep(i,n+1){
        append(g,{});
    }
    int a,b;
    rep(i,m){
        cin>>a>>b;
        append(g.at(a),b);
        append(g.at(b),a);
    }
    vector<int> prev;
    rep(i,n){
        append(prev,0);
    }
  prev.at(0)=1;
    int count=0;
    dfs(1,prev,count,g);
    cout<<count<<endl;



    return 0;
}