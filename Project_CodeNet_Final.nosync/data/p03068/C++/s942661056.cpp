#include <iostream>

using namespace std;

int main()
{
    int N, K;
    string S;
    cin >> N >> S >> K;
    const char kthChar = S[K-1];
    string result = "";
    for(const char &ch : S){
        if(ch == kthChar){
            result += ch;
        }
        else{
            result += '*';
        }
    }
    cout << result;
}