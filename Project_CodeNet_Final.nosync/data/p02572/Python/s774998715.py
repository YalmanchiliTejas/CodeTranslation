n = int(input())
arr = list(map(int, input().split()))
s = sum(arr)
res = 0
mod = int(1e9 + 7)
for i in arr:
  s -= i
  res += i * s
  res %= mod
print(res)