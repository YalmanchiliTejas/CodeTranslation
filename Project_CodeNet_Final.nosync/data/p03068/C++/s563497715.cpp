#include<iostream>
#include <fstream>
#include <vector>

#define LOCAL  1
#define UPLOAD 2

using namespace std;

int main()
{
#if ENVIRONMENT == LOCAL
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    int N;
    string S;
    int K;
    cin >> N;
    cin >> S;
    cin >> K;

    for(int i=0;i<N;i++){
        if(S[i] != S[K-1]){
            S[i] = '*';
        }
    }
    
    cout << S << endl;

    return 0;
}
