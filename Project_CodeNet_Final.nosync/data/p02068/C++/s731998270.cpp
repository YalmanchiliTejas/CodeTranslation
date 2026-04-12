#include<iostream>
#include<vector>
#include<set>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

#define MAX_N 100005
typedef long long ll;
vector<int> prime;
bool is_prime[MAX_N];

void sieve(int n){
    for(int i=0;i<=n;i++){
        is_prime[i] = true;
    }
    is_prime[0] = is_prime[1] = false;
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            prime.push_back(i);
            for(int j=2*i;j<=n;j+=i){
                is_prime[j] = false;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    rep(i,n)cin >> a[i];
    sieve(100000);
    set<int> st;
    rep(i,n){
        int k = a[i];
        rep(j,prime.size()){
            if((ll)prime[j]*prime[j] > k){
                break;
            }
            while(k%prime[j]==0){
                st.insert(prime[j]);
                k/=prime[j];
            }
        }
        if(k!=1){
            st.insert(k);
        }
    }
    // for(auto x:st){
    //     cerr << x << endl;
    // }
    ll mx = 0;
    for(auto x:st){
        ll tmp = 0;
        rep(i,n){
            if(a[i]%x==0){
                tmp+=a[i];
            }
        }
        mx = max(mx,tmp);
    }
    cout << mx << endl;

    return 0;
}
