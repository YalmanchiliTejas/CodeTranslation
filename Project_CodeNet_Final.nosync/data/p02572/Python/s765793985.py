n = int(input())
a = list(map(int,input().split()))

mod = int(1e9+7)
suffix_sum = sum(a)
ans = 0

for ai in a:
  suffix_sum -= ai
  ans += ai*suffix_sum
  ans %= mod

print(ans)