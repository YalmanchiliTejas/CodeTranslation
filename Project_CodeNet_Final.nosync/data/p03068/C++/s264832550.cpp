#include <iostream>
#include <string>
using namespace std;

#ifdef DEBUG
    #define IFD if(true)
#else
    #define IFD if(false)
#endif

int main()
{
    int N, K;
    string S;

    cin >> N >> S >> K;

    for(int i = 0; i < S.length(); i++) {
        cout << (S[i] == S[K - 1] ? S[i] : '*');
    }
    cout << endl;

    return 0;
}
