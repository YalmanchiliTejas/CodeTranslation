#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int s;
    cin>>s;
    int n=0,m=s;
    while (m>=15) {
        m=m-15;
        n++;
    }
    cout<<800*s-200*n<<endl;
    return 0;
}
