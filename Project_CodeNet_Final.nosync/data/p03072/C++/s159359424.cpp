#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    std::vector<int> hight(N);
    for(int i=0; i < N; i++){
        cin >> hight.at(i);
    }
    int max_mt = 0;
    int res = 0;
    for(int i=0; i < N; i++){
        if(hight.at(i) >= max_mt){
            res ++;
        }
        max_mt = max(max_mt, hight.at(i));
    }
    cout << res << endl;
    return 0;

}
