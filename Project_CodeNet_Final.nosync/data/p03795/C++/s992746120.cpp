#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
    int N,count = 0,x = 0,y = 0;
    cin >> N;
    for(int i = 0;i<N;i++){
        x+=800;
        count++;
        if(count == 15){
            y+=200;
            count = 0;
        }
    }
    cout << x-y << endl;
    return 0;
}
