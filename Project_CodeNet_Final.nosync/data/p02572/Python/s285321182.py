n = int(input())
a = list(map(int, input().split()))
c = 10 ** 9 + 7

ans = 0
tmp_val = 0
for i in range(n):
  tmp_val = (tmp_val + a[i]) % c

for i in range(n-1):
  tmp_val = (tmp_val - a[i]) % c
  ans += (tmp_val * a[i]) % c

print(ans % c)
