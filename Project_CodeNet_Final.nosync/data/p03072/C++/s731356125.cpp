#include <bits/stdc++.h>
using namespace std;

int main()
{
    int  N;
    cin >> N;
    int Hi;
    int maxH = 0;
    int res=0;
    for(int i=0;i<N;i++){
        cin >> Hi;
        if(Hi >= maxH){
            res++;
            maxH = Hi;
        }
    }
    cout<<res<<endl;

    return 0;
}