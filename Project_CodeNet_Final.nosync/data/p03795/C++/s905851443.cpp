#include<iostream>
using namespace std;
int main(void){
        int N,x,y;

        cin >> N;
        x = 800*N;
        y = 200*(int)(N/15);

        cout << x-y << endl;
return 0;
}
