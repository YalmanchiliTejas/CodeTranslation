n = int(input())
hlist = list(map(int,input().split()))

ans = 1
for i in range(1,len(hlist)):
    if hlist[i] >= max(hlist[:i]):
        ans+=1
print(ans)