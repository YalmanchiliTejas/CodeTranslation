n=int(input())
H=[int(i) for i in input().split()]
m=0
ans=0
for i in range(n):
  if H[i]>=m:
    m=H[i]
    ans+=1
print(ans)