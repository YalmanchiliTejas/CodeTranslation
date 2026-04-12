#124 b
n=int(input())
h=list(map(int,input().split()))
ans=1
for i in range(1,n):
    best=h[i]
    for j in range(i):
        if best<h[j]:
            best=h[j]
    if best==h[i]:
        ans+=1
print(ans)