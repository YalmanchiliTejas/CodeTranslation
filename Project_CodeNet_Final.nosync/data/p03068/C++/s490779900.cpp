#include<iostream>

using namespace std;

int main(){

    int n, k;
    char src;

    cin >> n;

    char s[n];

    cin >> s >> k;

    src = s[k - 1];

    for(int i = 0;i < n;i++){

        if(src != s[i]){

            s[i] = '*';
        }
    }

    cout << s << endl;

    return 0;
}