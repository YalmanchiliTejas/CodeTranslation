#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

main()
{
    int n, c = 1, a;
    cin >> n;
    int arr[n];
    cin >> arr[0];
    a = arr[0];
    for(int i = 1; i < n; i++){
        cin >> arr[i];
        if(a <= arr[i]){
            a = arr[i];
            c++;
        }
    }
    cout << c;


}





///promy_pompom
//hello world
