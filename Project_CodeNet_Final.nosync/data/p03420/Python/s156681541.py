n, k = (int(x) for x in input().split())
ans = 0
for b in range(k + 1, n + 1):
    m = n // b
    ans += m * (b - k)  # [k,b)
    ans += max(0, (n % b) - max(0, k - 1))
print(ans)
