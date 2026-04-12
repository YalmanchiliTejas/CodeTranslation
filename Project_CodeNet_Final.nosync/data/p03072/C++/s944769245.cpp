#include <bits/stdc++.h>
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<string, int, int> TU;
typedef tuple<int, int, int> TI;

int main()
{
    ll n;
    cin >> n;
    int input1[n];
    rep0(i,n){
        cin >> input1[i];
    }
    ll max=0,res=0;
    rep0(i,n){
        if(max<=input1[i]){
            res++;
            max=input1[i];
        }        
    }
    cout << res << endl;


}
