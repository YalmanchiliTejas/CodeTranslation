#include <iostream>

using namespace std;

long long int cmb(long long int i, long long int j) {
    if(j<0) return 0;
    
    long long int ret=1;
    for(long long int x=i; x>i-j; x--) {
        ret *= x;
    }
    for(long long int x=j; x>0; x--) {
        ret /= x;
    }
    return ret;
}

int main() {
    string N;
    long long int K;
    cin >> N >> K;
    long long int pow[4]={1, 9, 9*9, 9*9*9};
    
    long long int ans=0;
    if(N.size()-1>=K) {
        ans += cmb(N.size()-1, K)*pow[K];
    }

    if(N.size()>=K) {
        ans += cmb(N.size()-1, K-1)*pow[K-1]*(N[0]-'1');
        
        if(K==1) {
            ans++;
        } else if(K==2) {
            int i=1;
            while(i<N.size() && N[i]=='0') {
                i++;
            }

            if(i>N.size()-1) {
                ;
            } else {
                ans += cmb(N.size()-1-i, K-1)*pow[K-1]+(long long int)(N[i]-'0');
            }
        } else if(K==3) {
            int i=1;
            while(i<N.size() && N[i]=='0') {
                i++;
            }
            
            if(i>N.size()-1) {
                ;
            } else {
                ans += cmb(N.size()-1-i, K-1)*pow[K-1];
                ans += cmb(N.size()-1-i, K-2)*pow[K-2]*(long long int)(N[i]-'1');

                int j=i+1;
                while(j<N.size() && N[j]=='0') {
                    j++;
                }

                if(j<=N.size()-1) {
                    ans += cmb(N.size()-1-j, K-2)*pow[K-2]+(long long int)(N[j]-'0');
                }
            }
        }
    }
    
    cout << ans << endl;

    return 0;
    
}