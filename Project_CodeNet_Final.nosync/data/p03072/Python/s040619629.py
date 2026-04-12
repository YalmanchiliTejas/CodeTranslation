n=int(input())
h=list(map(int,input().split()))
ans=0
tmp=0
for i in range(n):
    if h[i]>=tmp:
        tmp=h[i]
        ans+=1
print(ans)