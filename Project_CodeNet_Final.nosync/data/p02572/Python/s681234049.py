n = int(input())
list_A = list(map(int, input().split()))
s = sum(list_A)
ans = 0
mod = pow(10, 9) + 7

for i in range(n):
    s -= list_A[i]
    ans += list_A[i] * (s % mod)
    ans %= mod

print(ans)