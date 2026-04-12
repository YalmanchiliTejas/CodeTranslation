#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;i++)

typedef pair<int, int>P;

int main(){
    int N;
    cin >> N;
    vector<P>vec;
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        if(i%2==0)vec.push_back(P(i,a));
        else vec.push_back(P(-i, a));
    }
    sort(vec.begin(), vec.end());
    if(N%2)reverse(vec.begin(), vec.end());
    for(int i=0;i<N;i++){
        cout<<vec[i].second;
        if(i+1==N)cout<<endl;
        else cout << " ";
    }
    return 0;
}