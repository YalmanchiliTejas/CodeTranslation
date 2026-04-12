n=int(input())
h=list(map(int, input().split()))
ans=1
b=[0]*n
b[0]=h[0]
for i in range(1,n):
    if max(b)<=h[i]:
        ans+=1
        b[i]=h[i]
print(ans)
