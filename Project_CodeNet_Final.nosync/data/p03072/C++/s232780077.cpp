#include <iostream>

using namespace std;

int main ()
{
    int n;
    cin>>n;
    int A[n];
    int shuma=1;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    int min=A[0];
    for(int i=1;i<n;i++)
    {
        if(A[i]>=min)
        {
            shuma++;
            min=A[i];
        }
    }
    cout<<shuma<<endl;
    return 0;
}
