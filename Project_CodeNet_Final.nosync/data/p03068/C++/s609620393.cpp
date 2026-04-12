#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]){
    int N;
    string S;
    int K;

    cin >> N >> S >> K;

    for(auto&& s: S){
        if (s == S[K-1]){
            cout << s;
        } else {
            cout << '*';
        }
    }
    cout << endl;

    return 0; 
}