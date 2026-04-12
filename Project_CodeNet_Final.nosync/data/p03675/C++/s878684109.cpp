
#include<bits/stdc++.h>
using namespace std;
int arr[200005];
int main()

{

    int n;
   map<int,int>v;
    cin >> n;
    for(int i =0;i<n;i++)
    {
        cin >> arr[i];

        v.insert(make_pair(i+1,arr[i]));
    }
    if(n%2==0){
            for(int i =n;i>=2;i-=2)
            {

                cout << v[i] <<" ";
            }
            for(int i =1;i<n;i+=2)
            {

                cout << v[i] << " ";
            }

    }
    else
    {

         for(int i =n;i>=1;i-=2)
            {

                cout << v[i] << " ";
            }
          for(int i =2;i<=n;i+=2)
            {

                cout << v[i] <<" ";
            }


    }

    cout << endl;
}
