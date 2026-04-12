#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep2(i,a,b) for(ll i=(a);i<(b);i++)
#define all(a)  (a).begin(),(a).end()
#define pb emplace_back
#define INF (1e9+1)
//#define INF (1LL<<59)

int mp[1<<16];

int main(){
    rep(i,1<<16)mp[i] = -1;
    vector<pii> stamp;
    int n;
    cin>>n;
    rep(i,n){
        int h,w;
        cin>>h>>w;
        stamp.pb(pii(h,w));
    }
    
    vector<string> vs(4);
    rep(i,4)cin>>vs[i];
    
    
    queue<int> que;
    que.push((1<<16)-1);
    mp[(1<<16)-1] = 0;
    
    while(que.size()){
        int q = que.front();
        que.pop();
        int dist = mp[q];
        
        for(const auto &stm:stamp){
            int h,w;
            tie(h,w) = stm;
            for(int i=-h+1;i<4;i++){
                for(int j=-w+1;j<4;j++){
                    int r=0,g=0,b=0;
                    for(int ii = i;ii<i+h;ii++){
                        ii = max(ii,0);
                        if(ii>=4)break;
                        for(int jj = j;jj<j+w;jj++){
                            jj = max(jj,0);
                            if(jj>=4)break;
                            
                            if( (q>>(ii*4+jj))%2 && vs[ii][jj]=='R' )r++;
                            if( (q>>(ii*4+jj))%2 && vs[ii][jj]=='G' )g++;
                            if( (q>>(ii*4+jj))%2 && vs[ii][jj]=='B' )b++;
                            if( (bool)r + (bool)(g) + (bool)(b)>=2 )goto end_loop;
                        }
                    }
                end_loop:;
                    if( (bool)r + (bool)(g) + (bool)(b)==1 ){
                        int tmp = q;
                        for(int ii = max(0,i);ii<min(4,i+h);ii++){
                            for(int jj = max(0,j);jj<min(4,j+w);jj++){
                                tmp &= ~(1<<(ii*4+jj));
                            }
                        }
                        if(mp[tmp]==-1){
                            int count = 0;
                            rep(ii,4)rep(jj,4)if( (tmp>>(ii*4+jj))%2==0 )count++;
                            if(count==16){
                                cout<<dist+1<<endl;
                                return 0;
                            }
                            
                            que.push(tmp);
                            mp[tmp] = dist+1;
                        }
                    }
                }
            }
        }
    }
}