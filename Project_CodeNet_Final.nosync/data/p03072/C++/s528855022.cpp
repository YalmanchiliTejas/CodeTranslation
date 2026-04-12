#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <map>       // pair
#include <string>
#include <stdio.h>
using namespace std;

int main(int argc, const char *argv[])
{   
    int N;
    cin>>N;
    vector<int> H(N,0);
    for(int i = 0; i < N ; i ++)
    {
        cin>>H[i];
    }
    int count = 0;
    int check = 1;
    for(int i = 0;i < N;i++)
    {
        check = 1;
        for(int j = 0; j <i ; j ++)
        {
            if(H[i] < H[j])
            {
                check = 0;
            }
        }
        if(check == 1)
        {
            count++;
        }
    }

    cout<<count;

    return 0;
}