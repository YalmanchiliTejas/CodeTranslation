#include <iostream>
using namespace std;
int main()
{
    int n,h,m=0,co=0;
    int i=0;
    cin >> n;
    while(i<n){
        i++;
        cin >> h;
        if(m<=h){
            co++;
            m=h;
        }
    }
    cout << co << endl;
    return 0;
}