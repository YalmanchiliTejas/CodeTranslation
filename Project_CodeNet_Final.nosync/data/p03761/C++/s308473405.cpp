#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main(){

    int N;
    cin >> N;

    map <char, int> M;
    for (int i = 0; i < N; i++){
        string S;
        cin >> S;

        map <char, int> m;
        
        for (int j = 0; j < S.length(); j++){
            m[S[j]]++;
        }

        if (i == 0){
            M = m;
        }else{
            for (int j = 'a'; j <= 'z'; j++){
                if (m[j] < M[j]){
                    M[j] = m[j];
                }
            }
        }
    }

    for (int i = 'a'; i <= 'z'; i++){
        if (M[i] > 0){
            for (int j = 0; j < M[i]; j++){
                char a = i;
                cout << a;
            }
        }
    }
    cout << endl;

    return 0;
}