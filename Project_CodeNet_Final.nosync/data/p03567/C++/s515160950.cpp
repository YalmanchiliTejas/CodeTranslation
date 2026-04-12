#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;cin >> str;
    bool result = false;
    for(int a = 0;a < str.size()-1;a++){
        string b;
        b.clear();
        b += str.at(a);
        b+= str.at(a+1);
        //cout<<b<<endl;
        if(b == "AC"){
            result = true;
            break;
        }
    }
    cout<<(result?"Yes":"No")<<endl;
    return 0;
}
