#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    for (int i = 0; i < s.size()-1; i++)
    {
        if(s.substr(i, 2) == "AC"){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
