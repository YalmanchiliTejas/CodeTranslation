n = int(input())
H = list(map(int, input().split()))
ans = 0
t = 0

for i in range(n):
  t = max(t,H[i])
  if(t == H[i]):
    ans += 1
print(ans)