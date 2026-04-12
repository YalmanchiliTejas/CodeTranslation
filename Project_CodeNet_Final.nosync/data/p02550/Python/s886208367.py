from collections import defaultdict
d = defaultdict(int)

n,x,m= map(int, input().split())
ans=0
v=[]
cnt=x
for i in range(m+10):
    if cnt==0 or i==n:
        print(ans)
        exit()

    elif d[cnt]==0:
        v.append(cnt)
        ans += cnt
        d[cnt]=i
        cnt = pow(cnt, 2, m)
    else:
        # 周期の始まり
        y=d[cnt]
        break
u=0
for i in range(y,len(v)):
    u+=v[i]
l=len(v)-y
xx=(n-len(v))//l
yy=(n-len(v))%l
ans+=xx*u+sum(v[y:y+yy])
print(ans)