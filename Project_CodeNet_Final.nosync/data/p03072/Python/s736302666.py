n = int(input())
h = list(map(int,input().split()))
ans = 1
for i in range(1,n):
  li = h[0:i+1]
  if max(li) == h[i]:
    ans+=1
print(ans)