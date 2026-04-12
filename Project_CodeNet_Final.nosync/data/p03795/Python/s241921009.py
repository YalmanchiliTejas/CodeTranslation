n = int(input())
ans = 0
for i in range(n):
  ans += 800
  if (i+1) % 15 == 0:
    ans -= 200
print(ans)