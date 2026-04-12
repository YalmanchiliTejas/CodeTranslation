#include<bits/stdc++.h>
#define rp(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;

int main() {
    int n;
    cin >> n;
    int hmax=0;
    int c=0;
    rp(i,n){
        int h;
        cin >> h;
        if(h>=hmax){
            hmax=h;
            c++;
        }
    }
    cout << c << endl;
    return 0;
}