#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int N, M;
    string ans;
    cin >> N >> M;
    if (N == M){
         ans = "Yes";
    }
    else{
        ans = "No";
    }
    cout << ans << endl;
}
