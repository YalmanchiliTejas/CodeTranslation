#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int N;
    cin >> N;
    string s;
    cin >> s;
    int K;
    cin >> K;
    int i;
    for(i=0;i<N;i++)
    {
        if(s[i] != s[K-1])
        {
            s[i] = '*';
        }
    }
    cout << s;
    return 0;
}