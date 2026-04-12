#include <cstdio>
#include <algorithm>

int n;
std::pair<int,int> bags[200020];
std::pair<int,int> balls[400040];

int main(void)
{
    long long answer;
    int i;
    int a,b,c;

    //freopen("x.in","r",stdin);

    scanf("%d",&n);
    if(n == 1)
        return puts("0"),0;

    a = 0,b = 0x7f7f7f7f;
    for(i = 0;i < n;++i)
    {
        scanf("%d %d",&bags[i].first,&bags[i].second);
        if(bags[i].first < bags[i].second)
            std::swap(bags[i].first,bags[i].second);
        b = std::min(b,bags[i].first);
        a = std::max(a,bags[i].second);
    }

    std::sort(bags,bags + n);
    for(i = 0;i < n;++i)
    {
        balls[i << 1].first = bags[i].first;
        balls[(i << 1) | 1].first = bags[i].second;
        balls[i << 1].second = balls[(i << 1) | 1].second = i;
    }
    std::sort(balls,balls + (n << 1));

    answer = 1ll * (balls[(n << 1) - 1].first - b) * (a - balls[0].first);
    if(balls[0].second != balls[(n << 1) - 1].second || balls[0].first == balls[1].first || balls[(n << 1) - 1].first == balls[(n << 1) - 2].first){
        c = 0x7f7f7f7f;
        for(i = (n << 1) - 1;i >= 0;--i)
        {
            c = std::min(c,balls[i].first - b);
            b = std::min(b,std::min(bags[balls[i].second].second,bags[balls[i].second].first));
            if(std::min(bags[balls[i].second].second,bags[balls[i].second].first) == balls[i].first)
                break;
        }
        answer = std::min(answer,1ll * c * (balls[(n << 1) - 1].first - balls[0].first));
    }
    printf("%lld\n",answer);

    return 0;
}