n=int(input())
h=[int(i) for i in input().split()]
ans=0
for i in range(n):
    if h[i]==max(h[:i+1]):
        ans+=1
print(ans)