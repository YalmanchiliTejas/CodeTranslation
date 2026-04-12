#include<bits/stdc++.h>
using namespace std;

#define rp(i,n) for(int i=0;i<n;i++)
#define rep(i,m,n) for(int i=m;i<=n;i++)
#define llrp(i,n) for(long long i=0;i<n;i++)
#define llrep(i,m,n) for(long long i=m;i<=n;i++)
#define sort(a) sort(a.begin(),a.end())
#define reverse(a) reverse(a.begin(),a.end())
#define pb push_back
#define elif else if
#define vcin(a); rp(i,a.size()){cin>>a[i];}
#define vcout(a); rp(i,a.size()){cout<<a[i]<<endl;}
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef string S;
typedef pair<int,int> P;

bool isOK(int index, int key,vi a) {
    if (a[index] >= key) return true;
    else return false;
}

int binary_search(int key,vi a) {
    int left = -1;
    int right = (int)a.size();
    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        
        if (isOK(mid, key,a)) right = mid;
        else left = mid;
    }
    return right;
}

int modpow(int a,int b,int p){
    if(b==0){
        return 1;
    }elif(b%2==0){
        return modpow((a*a)%p,b/2,p);
    }else{
        return (a*modpow(a,b-1,p))%p;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h,w;
    cin >> h >> w;
    char A[h][w];
    bool pass[h][w];
    rp(i,h){
        cin>>A[i];
        rp(j,w){
            pass[i][j]=(A[i][j]=='#'?false:true);
        }
    }
    int x=0;
    rp(i,h){
        while(x<w){
            pass[i][x]=true;
            if(i==h-1&&x==w-1){
                break;
            }elif(i==h-1&&x<w-1){
                if(A[h-1][x+1]=='#'){
                    x++;
                }else{
                    cout << "Impossible" << endl;
                    return 0;
                }
            }elif(i<h-1&&x==w-1){
                if(A[i+1][w-1]=='#'){
                    break;
                }else{
                    cout << "Impossible" << endl;
                    return 0;
                }
            }else{
                if(A[i+1][x]=='#'){
                    if(A[i][x+1]=='.'){
                        break;
                    }else{
                        cout << "Impossible" << endl;
                        return 0;
                    }
                }elif(A[i][x+1]=='#'){
                    if(A[i+1][x]=='.'){
                        x++;
                    }else{
                        cout << "Impossible" << endl;
                        return 0;
                    }
                }else{
                    cout << "Impossible" << endl;
                    return 0;
                }
            }
        }
    }
    bool all_ok=true;
    rp(i,h){
        rp(j,w){
            if(pass[i][j]==false){
                all_ok=false;
            }
        }
    }
    if(all_ok){
        cout << "Possible" << endl;
    }else{
        cout << "Impossible" << endl;
    }
    return 0;
}
