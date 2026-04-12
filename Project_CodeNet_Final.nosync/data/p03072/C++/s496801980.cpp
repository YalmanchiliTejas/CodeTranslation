#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int count=1;
    int maxh;
    int N;
    cin >> N;
    int H[30];
    for(int i=0;i<N;i++){
        cin >> H[i];
    }
    maxh=H[0];
    for(int j=1;j<N;j++){
    if(H[j]>=maxh){
    count++;
    maxh=H[j];
    }
    }
    cout << count <<endl;

}