#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

int main()
{
    char a, b, c;
    cin >> a >> b >> c;
    string s;
    s+=a;
    s+=b;
    s+=c;
    int d = stoi(s);
    if(d % 4 == 0){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    
    return 0;
}