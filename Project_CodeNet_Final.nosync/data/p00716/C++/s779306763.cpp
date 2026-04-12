#include <iostream>
#include <algorithm>

using namespace std;

int tanri(int y, int A, int fee, double rate){
    int sum = 0;
    for(int i=0; i < y; i++){
        sum += (int)A*rate;
        A -= fee;
    }
    return A+sum;
}

int hukuri(int y, int A, int fee, double rate){
    for(int i=0; i < y; i++){
        A += (int)(A*rate)-fee;
    }
    return A;
}

int main(){
    int n;
    cin >> n;
    for(int p=0; p < n; p++){
        long long money;
        cin >> money;
        int y, m;
        cin >> y >> m;

        int res = 0;
        for(int i=0; i < m; i++){
            int s, fee;
            double rate;
            cin >> s >> rate >> fee;
            if(s == 0) res = max(res, tanri(y, money, fee, rate));
            else res = max(res, hukuri(y, money, fee, rate));
        }
        cout << res << endl;
    }
}