#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin>>N;
    int x;
    x=800*N;
    int b,y;
    b=N/15;
    y=b*200;
    cout<<x-y<<endl;
}