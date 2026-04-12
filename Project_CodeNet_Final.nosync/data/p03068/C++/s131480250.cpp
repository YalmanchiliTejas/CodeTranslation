#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

void input_vector(int &x);
void show(int x);

//#define DEBUG
using namespace std;

int main(){
    int N;
    string S;
    int K;
    cin >> N;
    cin >> S;
    cin >> K;
    char a = S.at(K-1);
    for(int i = 0; i < S.length(); i++){
        if( S.at(i) != a){
            S.at(i) = '*';
        }
    }
    cout << S << endl;
}