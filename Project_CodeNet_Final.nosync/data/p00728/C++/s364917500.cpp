#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int N,S,sum,mx,mn;
    while(cin >> N && N>0)
    {
        sum = 0;
        mx = -1;
        mn = 1001; 
        for(int i=0; i<N; ++i)
        {
            cin >> S;
            sum += S;
            mx = max(S,mx);
            mn = min(S,mn);
        }
        cout << (sum - mx - mn) / (N - 2) << endl;
    }
}
