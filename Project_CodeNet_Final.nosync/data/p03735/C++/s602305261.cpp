#include<cstdio>
#include<algorithm>
#include<vector>
long long xy[400000];
typedef std::pair<long long,long long> pii;
int main(){
    int n;
    scanf("%d",&n);
    std::vector<pii> vp;
    for(int i=0;i<n;i++){
        long long x,y;
        scanf("%lld%lld",&x,&y);
        xy[2*i]=x;
        xy[2*i+1]=y;
        if(x<y)vp.push_back({x,y});
        else vp.push_back({y,x});
    }
    std::sort(xy,xy+(2*n));
    long long xy_min=xy[0], xy_max=xy[2*n-1], smaller_max=0, larger_min=1e15;
    for(int i=0;i<n;i++){
        if(vp[i].first>smaller_max)smaller_max=vp[i].first;
        if(vp[i].second<larger_min)larger_min=vp[i].second;
    }
    long long ans1=(smaller_max-xy_min)*(xy_max-larger_min);
    std::sort(vp.begin(),vp.end());
    long long choice_min=1e15, choice_max=0, choice_dif=vp[n-1].first-vp[0].first;
    for(int i=0;i<n-1;i++){
        if(vp[i].second<choice_min)choice_min=vp[i].second;
        if(vp[i].second>choice_max)choice_max=vp[i].second;
        long long dif_tmp=std::max(choice_max,vp[n-1].first)-std::min(choice_min,vp[i+1].first);
        if(dif_tmp<choice_dif)choice_dif=dif_tmp;
    }
    long long ans2=(xy_max-xy_min)*choice_dif;
    if(ans1<ans2)ans2=ans1;
    printf("%lld\n",ans2);
    return 0;
}