#include <iostream>
#include<string>
using namespace std;

int main(){
    int N,K;
    cin >> N;

    std::string S;
    std::string ans;

    cin >> S;
    cin >> K;

    std::string sub = S.substr(K - 1,1);

    for (int i = 0;i < N; i++){
        std::string a = S.substr(i,1);
        if(a == sub){
            ans += a;
        }else{
            ans += "*";
        }
    }

    cout << ans << endl;

}