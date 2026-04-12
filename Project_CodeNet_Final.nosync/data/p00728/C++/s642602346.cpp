#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin >> n, n != 0){
        int sum = 0, maxi = 0, mini = 1000;
        for(int i=0;i<n;++i){
            int s;
            cin >> s;
            sum += s;
            maxi = max(maxi, s);
            mini = min(mini, s);
        }
        cout << (sum- maxi - mini) / (n - 2) << endl;
    }

    return 0;
}
