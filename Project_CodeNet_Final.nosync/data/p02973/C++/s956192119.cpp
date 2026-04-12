#include<bits/stdc++.h>
using namespace std;
int MIN=9999;
string S;
long long int MOD = 1000000007;
const int MAX = 1000001;
long long int fac[MAX],finv[MAX], inv[MAX];

void COMinit(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i=2;i<MAX;i++){
        fac[i] = fac[i-1]* i % MOD;
        inv[i] = MOD - inv[MOD%i]*(MOD/i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}

long long COM(int n,int k){
    if(n < k)return 0;
    if(n < 0 || k< 0)return 0;
    return fac[n]*(finv[k]*finv[n-k] % MOD) % MOD;
}

int main(){
    long long int N,K,p[200001],k[200001],A[200001];
    cin >> N;
    for(int i=0;i<N;i++)
        cin >> A[i];
    vector<int> vec;
    for(int i=0;i<N;i++){
        int ind = -1;
        if(vec.size()==0){
            vec.push_back(A[i]);
        }else if(vec[vec.size()-1] >= A[i])
            vec.push_back(A[i]);
        else{
            ind = vec.size() - (lower_bound(vec.rbegin(),vec.rend(),A[i]) - vec.rbegin());
            if(ind == vec.size() || ind == -1){
                vec[0] = A[i];
            }else{
                vec[ind] = A[i];
            }
        }
        /*
        cout << "---" << endl;
        cout << "ind : " << ind << endl; 
        for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
        */
    }
    cout << vec.size() << endl;
    return 0;
}