def binary_search(c1, c2):
    m = (c1 + c2 + 1) // 2
    if abs(c1 - c2) <= 1:
        return m
    else:
        if dp[m] < a:
            c1 = m
        else:
            c2 = m
        return binary_search(c1, c2)

n = int(input())
dp = [-1 for _ in range(n)]
for _ in range(n):
    a = int(input())
    m = binary_search(n - 1, -1)
    dp[m] = a
ans = 0
for i in dp:
    if i == -1:
        break
    else:
        ans += 1
print(ans)