#include <bits/stdc++.h>
#define rep(i ,n) for(int i=0;i<(int)(n);++i)
using namespace std;
typedef long long int int64;
typedef unsigned long long uint64;

int n;


int binary_search(vector<int> &a ,int k){
    int low , mid , high;
    low = 0;
    high = n - 1;
    while( low <= high ){
        mid = (low + high) / 2;
        if(k == 0 ) return 0;
        if(k == a[mid] ) {
            if( a[mid-1]!=k && mid-1>=0 ) return mid;
            else if(mid == 0) return 0;
            else high = mid - 1;
        }
        else if(k < a[mid]) {
            high = mid - 1;
        }
        else if(k > a[mid]) {
            if( k <= a[mid+1]) return mid + 1;
            low = mid + 1;
        }
    }
    if(a[mid]>k && a[mid-1]<k && mid-1>=0) return mid;
    if(a[mid]<k && a[mid+1]>k && mid+1<=n-1) return mid+1;
    if(a[0]>k) return 0;
    return n;
}



int main(){
    cin >> n;
    vector<int> a(n);
    rep(i ,n) cin >> a[i];
    int q; cin >> q;
    rep(i ,q){
        int k; cin >> k;
        cout << binary_search(a , k) << endl;
    }
}

