N = int(input())
A = [int(i) for i in input().split()]
mod = 10**9 + 7
sum_A = sum(A)
ans = 0
for i in A:
  ans += i * (sum_A := sum_A - i) % mod
  
print(ans % mod)  
  