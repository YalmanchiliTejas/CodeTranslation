n,x,m = map(int, input().split())
visited=set()
from collections import defaultdict
ans=0
cnt=0
now=x
last=defaultdict(list)
while cnt!=n:
    cnt+=1
    if now in visited:
        break
    visited.add(now)
    last[now]=[ans,cnt]
    ans+=now

    now=(now**2) % m
    if now==0:
        print(ans)
        exit()

if cnt==n:
    print(ans)
    exit()

looplen=cnt-last[now][1]
looppoint=ans-last[now][0]
loopcnt,nokori = divmod(n-cnt,looplen)
ans+=(loopcnt*looppoint)
ans+=now

for i in range(nokori):
    now=(now**2) % m
    ans+=now

print(ans)