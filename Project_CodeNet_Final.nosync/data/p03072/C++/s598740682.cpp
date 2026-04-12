#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

int main(void)
{
    //input
    int N;
    vector<int> H;
    cin>>N;
    for(int i=0; i<N; i++)
    {
        int temp;
        cin>>temp;
        H.push_back(temp);
    }

    //calc
    int count=1;
    for(int i=N-1; i>0; i--)
    {
        int j=i-1;
        for(;j>=0; j--)
        {
            if(H[j] > H[i])
            {
                break;
            }
        }
        if(j==-1) 
        {
            count++;
        }
    }

    //output
    cout<<count<<endl;

    return 0;
}