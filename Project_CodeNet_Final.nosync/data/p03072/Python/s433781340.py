n=int(input())
h=[int(x) for x in input().split()]
ans=0
for i in range(n):
  if h[i] >= max(h[:i+1]):
    ans+=1
print(ans)