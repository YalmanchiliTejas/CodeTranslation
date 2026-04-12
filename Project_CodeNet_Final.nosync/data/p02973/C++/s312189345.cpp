#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A;

    int ans = 0;

    for(int i = 0; i<N; i++){
        int a;
        cin >> a;
        auto itr = upper_bound(A.begin(), A.end(), a-1);
        if(itr == A.begin()){
            A.insert(A.begin(), a);
            ans ++;
        }
        else{
            *(itr -1) = a;
        }
    }
    cout << ans << endl;

    return 0;
}