#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
const int MAXN = 4e5+5;
multiset<int> s1;
int arr[MAXN];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(i == 1){
            s1.insert(arr[i]);
            continue;
        }
        
        auto it = s1.lower_bound(arr[i]);
        if(it != s1.begin()){
            it--;
        }
        
        
        if(*it>=arr[i]){
           
            s1.insert(arr[i]);
            
        }else{
             
            s1.erase(it);
            s1.insert(arr[i]);
        }
    }
    cout<<s1.size()<<endl;
}