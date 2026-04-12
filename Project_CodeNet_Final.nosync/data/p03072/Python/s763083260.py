n = int(input())
h = list(map(int, input().split()))
ans = 1
hmax = h[0]

for i in range(1,n):
  if hmax<=h[i]:
    ans = ans+1
    hmax=h[i]

print(ans)