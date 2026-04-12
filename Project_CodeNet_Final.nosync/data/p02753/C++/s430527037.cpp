#include "iostream"
using namespace std;
int main()
{
    int t = 1;
    //cin >> t;
    while(t--){
        string str;
        cin >> str;
        string s1 = "AAA", s2 = "BBB";
        if(str == s1 || str == s2)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}