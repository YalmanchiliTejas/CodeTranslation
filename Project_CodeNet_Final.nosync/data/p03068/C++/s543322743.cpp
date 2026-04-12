 #include <iostream>
 #include<cstdio>

 using namespace std;

int main()
{
    int n,k,i;
    char a[15];
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    cin>>k;
    for(i=0;i<n;i++)
    {
        if(a[i]==a[k-1])
            cout<<a[i];
        else cout<<"*";
    }
    cout<<endl;
    return 0;
}
