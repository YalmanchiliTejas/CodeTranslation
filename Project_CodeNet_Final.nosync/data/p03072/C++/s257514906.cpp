#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    
    int ans = 0,n,temp=0;
    cin >> n;
    vector<int> v(n);

    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    for(int i = n-1; i > 0; i--){
        for(int j = i-1; j >= 0; j--){
            if(v[i] >= v[j])
                temp++;
        }
        if(temp == i)
            ans++;
        temp = 0;
    }

    cout<<ans+1<<endl;

    return 0;
}