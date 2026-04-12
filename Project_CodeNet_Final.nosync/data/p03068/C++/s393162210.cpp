#include <iostream>
#include <string>
using namespace std;

int main(void){
    int n=0;
    string s;
    int k=0;
    char poyo=0;

    cin >> n;
    cin >> s;
    cin >> k;

    poyo=s[k-1];

    for(int i=0;i<n;i++){
        if(s[i]!=poyo)s[i]='*';
    }

    cout << s << endl;

    return 0;
}