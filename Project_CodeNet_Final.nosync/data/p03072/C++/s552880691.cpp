#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,cnt=0;cin>>N;
    int H[100];
    for(int i = 0; i < N; i++)
    {
        cin>>H[i];
    }

    for(int i = 1; i < N; i++)
    { int hoge=0;
        for(int j = 0; j < i; j++)
        {   
            hoge=max(H[j],hoge);}
            
           if (H[i]>=hoge) {
               cnt++;
           }
           
           
            }
            
            
            
        
        cout<<cnt+1<<endl;
        
    }
    
    