#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    int a = 0,b = 0;
    cin >> s;
    for(char c : s){
      switch(c){
        case 'A':
          a++;
          break;
        case 'B':
          b++;
      };
    }
    if(a != 0 && b != 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}