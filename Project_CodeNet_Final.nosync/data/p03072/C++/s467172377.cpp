#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int yama,before = 0,count = 0;
    for (int i=0;i<n;i++){
        cin >> yama;
        if (before <= yama){count++; before = yama;}
    }

    cout << count << endl;
}
