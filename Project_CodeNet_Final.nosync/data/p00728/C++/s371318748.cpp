#include<bits/stdc++.h>
using namespace std;

vector<int> v;

int main(){
    int n;
    while(1){
        cin >> n;
        if(n == 0)break;
        for(int i=0; i < n; i++){
            int tmp; cin >> tmp;
            v.push_back(tmp);
        }
        int sum = 0;
        sort(v.begin(), v.end());
        for(int i=1; i < n-1; i++){
            sum += v[i];
        }
        cout  << sum / (n - 2) << endl;
        v.clear();
    }

    return 0;
}

