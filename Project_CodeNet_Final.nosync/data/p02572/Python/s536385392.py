n = int(input())
a = list(map(int, input().split()))

sum = sum(a) - a[0]

ans = 0
for i in range(n):
  ans += a[i] * sum
  if (i == n-1):
    break
  else:
  	sum -= a[i+1]
  
ans %= 10 ** 9 + 7  
print(ans)