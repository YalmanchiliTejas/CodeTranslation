n = int(input())
a = list(map(int, input().split()))
subsum = a[n-1]
ans = 0
for b in reversed(a[:n-1]):
  ans = ans + b * subsum
  subsum = subsum + b
print(ans % (10**9 + 7))