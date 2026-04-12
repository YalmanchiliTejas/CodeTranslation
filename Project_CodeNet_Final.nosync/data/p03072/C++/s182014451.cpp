#include <bits/stdc++.h>
using namespace std;
using Int = long long int;
template<typename T> void swap(T *t1, T *t2){ T* tmp=t1; t1=t2; t2=tmp;}
Int tmpi = 0;
double tmpd = 0.0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Int n, h[1000];
    cin >> n;
    for(Int i=0; i<n; i++){
        cin >> h[i];
    }
    Int sum = 1;
    Int marker = h[0];
    for(Int i=1; i<n; i++){
        if(h[i] >= marker){
            sum++;
        }
        marker = h[i] > marker ? h[i] : marker;
    }
    cout << sum << endl;

    return 0;
}