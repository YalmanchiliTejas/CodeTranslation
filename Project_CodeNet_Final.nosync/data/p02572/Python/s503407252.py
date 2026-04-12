n = int(input())
arr = list(map(int, input().split()))
mod = 10**9 + 7

sum_arr = sum(arr)
sum_pow = 0

for a in arr:
  sum_pow = sum_pow + a*a

result = ((sum_arr*sum_arr) - sum_pow )//2 % mod

print(result)