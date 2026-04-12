#include<bits/stdc++.h>
using namespace std;

#define rp(i,n) for(int i=0;i<n;i++)
#define rep(i,m,n) for(int i=m;i<=n;i++)
#define lrp(i,n) for(long long i=0;i<n;i++)
#define lrep(i,m,n) for(long long i=m;i<=n;i++)
#define all(a) a.begin(),a.end()
#define pb push_back

typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef string S;

int main(){
    int h,w;
    cin >> h >> w;
    vs s(h);
    rp(i,h){
        cin >> s.at(i);
    }
    char A[h][w],B[h][w];
    rp(i,h){
        rp(j,w){
            A[i][j]=s.at(i).at(j);
            B[i][j]=s.at(i).at(j);
        }
    }
    
    rp(i,h){
        int cnt=0;
        rp(j,w){
            if(A[i][j]=='.'){
                cnt++;
            }
        }
        if(cnt==w){
            rp(j,w){
                B[i][j]='0';
            }
        }
    }
    
    rp(i,w){
        int cnt=0;
        rp(j,h){
            if(A[j][i]=='.'){
                cnt++;
            }
        }
        if(cnt==h){
            rp(j,h){
                B[j][i]='0';
            }
        }
    }
    
    rp(i,h){
        int cnt=0;
        rp(j,w){
            if(B[i][j]!='0'){
                cout << B[i][j];
                cnt++;
            }
        }
        if(cnt){
            cout << endl;
        }
    }

    return 0;
}
