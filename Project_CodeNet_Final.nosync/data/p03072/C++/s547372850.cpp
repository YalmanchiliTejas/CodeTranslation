#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int h[20];
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i ++){
        cin >> h[i];
    }
    int count = 1;
    for(int i = 1 ; i < n ; i++){
        bool a = true;
        for(int j = 0; j < i; j++){
            if(h[j] > h[i]) a = false;
        }
        if(a) count++;
    }
    cout << count << endl;
    return 0;
}
