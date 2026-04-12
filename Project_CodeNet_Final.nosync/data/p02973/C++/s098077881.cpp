#include<iostream>
#include<string>
#include<vector>
#include<algorithm>//sort,reverse
#include<utility>//pair
#include<queue>//queue,priority_queue
#include<deque>//double_ended queue
using namespace std;
typedef pair<int,int> P;//Pでpair<-,->を表す。
typedef long long LL; 



int main()
{ 
    int n;
    cin>>n;
    LL a[n];
    int ans=0;
    vector<LL> v;
    for(int i=0;i<n;i++){cin>>a[i];}
    for(int i=0;i<n;i++){
        if(v.empty()){ans++;v.push_back(a[i]);}
        else{
            LL x=v.back();
            if(x<a[i]){
                //二分探査
                int val_min=0;
                int val_max=v.size()-1;
                while(val_min!=val_max&&(val_min+1)!=val_max){
                    int val=(val_min+val_max)/2;
                    if(v[val]<a[i]){val_max=val;}
                    else{val_min=val;}
                }
                if(val_min==val_max){v[val_min]=a[i];}
                else{
                    if(v[val_min]<a[i]){v[val_min]=a[i];}
                    else{v[val_max]=a[i];}
                }
            }
            else{
                ans++;
                v.push_back(a[i]);
            }
        }
        /*cout<<i<<' ';
        for(int j=0;j<v.size();j++){
            cout<<v[j]<<' ';
        }
        cout<<endl;*/
    }
    cout<<ans<<endl;
    return 0;
}