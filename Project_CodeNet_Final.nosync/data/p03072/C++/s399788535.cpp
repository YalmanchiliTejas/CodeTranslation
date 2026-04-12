#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int h[n];
    int m=0;
    int co=0;
    for(int i=0;i<n;i++){
        cin >> h[i];
        if(m<=h[i]){
            co++;
            m=h[i];
        }
    }
    cout <<co<< endl;
    return 0;
}
