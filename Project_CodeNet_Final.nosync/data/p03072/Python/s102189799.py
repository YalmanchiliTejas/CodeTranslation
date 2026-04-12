n = int(input())
h = list(map(int,input().split()))
m = h[0]
ans = 1

for i in range(1,n):
  if h[i] >= m:
    m = h[i]
    ans = ans + 1

print(ans)