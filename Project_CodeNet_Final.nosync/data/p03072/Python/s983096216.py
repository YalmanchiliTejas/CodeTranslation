n=int(input())
h=list(map(int,input().split()))
a=h[0]
ans=0
for i in range(n):
    if h[i]>=a:
        ans+=1
        a=h[i]
print(ans)