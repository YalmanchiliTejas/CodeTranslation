#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long int ll;

int main()
{
    int N,K;
    string S;
    cin>>N>>S>>K;

    for(int i=0;i<N;++i)
        if(S[i]!=S[K-1])
            cout<<"*";
        else
            cout<<S[i];
    cout<<endl;
}
