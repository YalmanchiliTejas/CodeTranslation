#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

const int NMax = 100000 + 10;

int N;

int main() {

    cin>>N;
    int total = N*800,nr=(N/15),backM=nr*200;
    cout<<total-backM;

    return 0;
}



