n=int(input())
h=list(map(int,input().split()))
x=[h[0]]
ans=1
for i in range(1,n):
    if h[i-1]<=h[i] and max(x)<=h[i]:
        ans+=1
    x.append(h[i])
print(ans)    