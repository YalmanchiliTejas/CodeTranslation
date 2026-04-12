#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int num;
    cin >> num ;
    long long int M = 1000000000 + 7;
    vector<int> v(num);
    for(int i=0; i< num ; i++ ){
        cin >> v[i];
    }
    long long int sum = v[0];
    long long int ans = 0;
    for(int i = 1; i< num ; i++ ){
        ans = (ans + v[i]*sum)%(M);
        sum = (sum + v[i])%M;
    }
    cout << ans%(M) ;
    return 0;
}