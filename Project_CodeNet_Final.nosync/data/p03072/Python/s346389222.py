n=int(input())
h=[int(i) for i in input().split()]
ans=1
for i in range(1,n):
    if h[i]==max(h[0:i+1]):
        ans+=1
print(ans)