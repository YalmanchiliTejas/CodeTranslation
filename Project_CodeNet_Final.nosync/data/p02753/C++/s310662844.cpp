#include<bits/stdc++.h>

using namespace std;

template <typename T>std::string NumberToString ( T Number ){std::ostringstream ss; ss << Number;return ss.str(); } // Usages NumberToString(3)
template <typename T>T StringToNumber ( const string &Text ){istringstream ss(Text);T result;return ss >> result ? result : 0;} // StringToNumber<int>("3")

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;
    int count = 0;
    if(str[0] == 'A' || str[1] =='A' || str[2] == 'A'){
        count ++;
    }
    if(str[0] == 'B' || str[1] =='B' || str[2] == 'B'){
         count ++;
    }
    if(count==2) cout << "Yes" << endl;
    else cout << "No" << endl;




   return 0;
}