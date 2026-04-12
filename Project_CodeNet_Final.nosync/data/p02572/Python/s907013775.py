n = int(input())
a = list(map(int, input().split()))
mod = 10**9 + 7
sum_a = [0]*n
sum_a[0] = a[0]
for i in range(1, n):
    sum_a[i] = sum_a[i-1] + a[i]
#print(sum_a)
ans = 0
for i in range(n):
    sum_i = sum_a[n-1] - sum_a[i]
    ans = (ans + sum_i*a[i] % mod) % mod
print(ans % mod)