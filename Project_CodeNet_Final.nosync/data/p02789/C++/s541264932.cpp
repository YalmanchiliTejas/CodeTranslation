#include <iostream>

using namespace std;

int main()
{
    int n;
    int m;
    cin >> n;
    cin >> m;
    if(n>=m){
      if(n==m){
        cout << "Yes";
      }else {
        cout << "No";
      }
    }
    return 0;
    }