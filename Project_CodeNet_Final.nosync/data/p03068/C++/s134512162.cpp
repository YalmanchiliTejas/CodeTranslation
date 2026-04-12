#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    int K;
    cin >> K;
    
    char a = S.at(K - 1);
    
    for(int i = 0; i < S.size();i++){
        if(S.at(i) != a){
            S.at(i) = '*';
        }
    }
    
    cout << S << endl;
    
}
