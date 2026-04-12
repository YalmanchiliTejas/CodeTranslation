#include <iostream>
using namespace std;
int main(void){
    int X,Y,Z;
    cin>>X>>Y>>Z;
    int a=0;
    int answer;
    while (X-2*Z-Y-a*(Y+Z)>=0){
        answer=a;
        a++;
    }
    cout<<answer+1<<endl;
}
