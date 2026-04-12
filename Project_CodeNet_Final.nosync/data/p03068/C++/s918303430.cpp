#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    string s, s1;
    cin >> n >> s >> k;

    for (int i=0; i<n; i++){
        if (s[i]==s[k-1]){
            s1 = s1+s[i];
        }
        else{
            s1 = s1+'*';
        }
    }
    cout << s1 << endl;
    return 0;
}
