#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> H(N);
    for(int i=0; i < N; i++){
        cin >> H[i];
    }

    int res = 0;
    for (vector<int>::iterator it=H.begin(); it < H.end(); it++){
        // cout << "*it = " << *it << endl;
        int max = *max_element(H.begin(), it+1);
        // cout << "max = " << max <<endl;
        if(max == *(it)){
            res += 1;
        }
    }
    cout << res << endl;
    return 0;
}
