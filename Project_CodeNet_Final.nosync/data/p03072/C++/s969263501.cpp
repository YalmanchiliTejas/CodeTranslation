#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(void){
    int N;
    cin>>N;
    int max=0;
    int count=0;
    for(int i=0;i<N;i++){
        int h;
        cin>>h;
        if(h>=max){
            count++;
            max=h;
        }
    }
    cout<<count<<endl;
}
