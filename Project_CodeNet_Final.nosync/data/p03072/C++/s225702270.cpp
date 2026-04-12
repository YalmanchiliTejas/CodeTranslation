#include<iostream>
#include<vector>
using namespace std;

int main(){
    //inport
    int N;
    cin >> N;

    //process
    int max=0;
    int num=0;
    for(int i=0;i<N;i++){
        int in;
        cin >> in;
        if(in>=max){
            max=in;
            num++;
        }
    }

    //output
    cout << num << endl;

    return 0;
}
