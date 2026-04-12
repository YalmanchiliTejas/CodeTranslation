#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    string S;
    cin >> N >> S;
    vector<bool> responce;
    for(int i = 0; i < N; i++){
        responce.push_back(S[i] == 'o');
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            bool animals[N];
            animals[0] = i;
            animals[1] = j;
            for(int k = 2; k < N; k++){
                animals[k] = (responce[k - 1] ^ animals[k - 1] ^ animals[k - 2]);
            }
            if(!(animals[N - 2] ^ animals[N - 1] ^ animals[0] ^ responce[N - 1])){
                if(!(animals[N - 1] ^ animals[0] ^ animals[1] ^ responce[0])){
                    for(int k = 0; k < N; k++){
                        if(animals[k]){
                        cout << "S";
                        }else{
                            cout << "W";
                        }
                    }
                    return 0;
                }
            }
        }
    }
    cout << -1 << endl;
}