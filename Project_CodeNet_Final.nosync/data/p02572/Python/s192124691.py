N = int(input())
arr = list(map(int, input().split(" ")))

mod = 10 ** 9 + 7

s = sum(arr) % mod

result = 0
for i in arr:
  s -= i
  s %= mod
  result += s * i
  result %= mod
print(result)
