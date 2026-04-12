n = int(input())
h = list(map(int,input().split()))
ans=1
tp=h[0]
for j in range(1,n):
    if(h[j]>=tp):
        tp=h[j]
        ans+=1
print(ans)
