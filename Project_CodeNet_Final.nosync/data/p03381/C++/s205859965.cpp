    #include <cstdio>
    #include <algorithm>
    #include <vector>
    using namespace std;
    vector<int> vec;
    int ar[200005],ans1,ans2;
    int main(){
    int n;
    scanf("%d",&n);
    for(int a=1;a<=n;++a){
        scanf("%d",&ar[a]);
        vec.push_back(ar[a]);
    }
    sort(vec.begin(),vec.end());
        int mid=n/2;
        ans1=vec[mid-1];
        ans2=vec[mid];
    for(int a=1;a<=n;++a){
        if(ar[a]<=ans1){
            printf("%d\n",ans2);
        }else{
            printf("%d\n",ans1);
        }
    }
    return 0;}
