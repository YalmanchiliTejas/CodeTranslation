n = int(input())
line = list(map(int, input().split()))
ans = 0
x = sum(line)
mod = 10**9 + 7
for i in range(n):
  x -= line[i]
  ans += line[i] * x
  if ans > mod:
    ans = ans % mod
print(ans)