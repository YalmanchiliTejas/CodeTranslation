n, k = [int(i) for i in input().split()]
ans = 0
for i in range(1, n + 1):
    ans += (n // i) * (max(0, i - k))
    ans += max(n % i- k + 1, 0)
print(ans - (n if k==0 else 0))
