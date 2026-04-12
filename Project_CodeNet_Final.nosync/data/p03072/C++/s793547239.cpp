#include<iostream>
using namespace std;

int main(){
    int N, sum=1, flag=1;
    cin>>N;
    int H[N];
    for (int i = 0; i < N; i++)
    {
        cin>>H[i];
    }
    for (int i = 0; i < N-1; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            flag=1;
            if (H[i+1]<H[j])
            {
                flag=0;
                break;
            }
            
        }
        if (flag)
        {
            sum+=1;
        }
        
        
        
    }
    cout<<sum<<endl;
}