#include <bits/stdc++.h>

using namespace std;
using lint = long long;

int main(void)
{
    int N;
    cin >> N;
    vector<lint> a(N);
    for(auto &x: a){
        cin >> x;
    }
    vector<lint> ha;
    lint min = 0;
    ha.push_back(a[0]);
    min = a[0];
    for(int i = 1; i < N; i++){
        if(min >= a[i]){
            min = a[i];
            ha.push_back(a[i]);
            continue;
        }

        for(int k = 0; k < ha.size(); k++){
            if(ha[k] < a[i]){
                if(k == ha.size()-1){
                    min = a[i];
                }
                ha[k] = a[i];
                break;
            }
        }
    }

    cout << ha.size() << endl;
    return 0;
}