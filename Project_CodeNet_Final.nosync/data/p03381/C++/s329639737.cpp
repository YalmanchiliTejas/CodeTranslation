#include <bits/stdc++.h>
using namespace std;

typedef struct{
    long i;
    long v;
} pair_t;

bool pless(const pair_t& a, const pair_t& b){
    if(a.v!=b.v){
        return a.v<b.v;
    }else{
        return a.i<b.i;
    }
}

long ifind(const vector<pair_t>& v, long ind){
    long n=v.size();
    for(long i=0; i<n; i++){
        if(v[i].i==ind){
            return i;
        }
    }
}

int main(void){
    long n;
    cin >> n;
    vector<pair_t> v(n);
    vector<long> f(n/2);
    for(long i=0; i<n; i++){
        v[i].i = i;
        cin >> v[i].v;
    }
    sort(v.begin(), v.end(), pless);
    for(long i=0; i<n/2; i++){
        f[i] = v[i].i;
    }
    sort(f.begin(), f.end());
    /*
    for(long i=0; i<n; i++){
        cout << v[i].i << " ";
    }
    cout << endl;
    for(long i=0; i<n; i++){
        cout << v[i].v << " ";
    }
    cout << endl;
    */
    for(long i=0; i<n; i++){
        auto k=binary_search(f.begin(), f.end(), i);
        //cout << "k=" << k << endl;
        if(k){
            cout << v[n/2].v << endl;
        }else{
            cout << v[n/2-1].v << endl;
        }
    }
    return 0;
}
