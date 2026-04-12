#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
#define pi 3.1415926

int a[(int)2e5][11];

int main(){
    string s;
    cin >> s;
    int br=0, br1=0;
    for(int i = 0; i < 3; i++){
        if(s[i] == 'A')
            br++;
        if(s[i] == 'B')
            br1++;
    }
    if(br == 2 || br1 == 2)
        cout << "Yes";
    else    
        cout << "No";
    

}

    

		
