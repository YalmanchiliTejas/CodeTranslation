#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<int> v(n);
    int cnt =1;
    for(int i=0;i<n;++i){
        cin>>v[i];
        for(int j=0;j<i;++j){
            if(v[i]<v[j])break;
            if(j==i-1)cnt++;
        }
    }
    cout << cnt << endl;
    
    return 0;
}
