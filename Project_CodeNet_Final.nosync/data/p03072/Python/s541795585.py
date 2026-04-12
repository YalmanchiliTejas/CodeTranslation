n=int(input())
h=list(map(int,input().split()))
ans=1

for i in range(1,n):
    a=0
    for j in range(i):
        if h[j]<=h[i]:
            a+=1
    if a==i:
        ans+=1
print(ans)
