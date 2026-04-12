#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<int> count_k(string x){
    vector<int> count; 
    rep(i,x.size()){
        count.push_back(int(x[x.size()-1-i]-'0'));
    }
    //reverse(count.begin(),count.end());
    return count;
}

int choose(int n,int k){
    int res = 1;
    rep(i,k){
        res*=n;
        n--;
    }
    rep(i,k){
        res/=(k-i);
    }
    return res;
}

int main(){
    string n;
    int k;
    cin >> n >> k;
    vector<int> N;
    N = count_k(n);

    int G[N.size()][4];

    /*
    int ref=0;
    for(int i=1;i<=n;++i){
        vector<int> p;
        p = count_k(i);
        int temp=0;
        rep(i,p.size()){
            if(p[i]!=0) temp++;
        }
        if(temp==k) ref++; 
    }
    cout <<"ref" << ref << endl;;
    */
    rep(i,N.size()){
        for(int j=1; j<=3; ++j){
            if(j==1){
                if(N[i]==0){
                    if(i==0) G[i-1][j]=0;
                    G[i][j]=G[i-1][j];
                    continue;
                }
                G[i][j]=N[i]+9*i;
            }
            if(j==2){
                if(i==0){
                    G[i][j]=0;
                    continue;
                }
                if(N[i]==0){
                    G[i][j]=G[i-1][j];
                    continue;
                }
                G[i][j]=choose(i,2)*81+choose(i,1)*9*(N[i]-1)+G[i-1][1];
            }
            
            if(j==3){
                if(i==0){
                    G[i][j]=0;
                    continue;
                }
                if(N[i]==0){
                    G[i][j]=G[i-1][j];
                    continue;
                }
                G[i][j]=choose(i,3)*81*9+choose(i,2)*81*(N[i]-1)+G[i-1][2];
            }
        }
    }
    /*
    rep(i,N.size()){
        rep(j,3) cout << G[i][j+1] << " ";
        cout << endl;
    }*/

    cout << G[N.size()-1][k] << endl;


}