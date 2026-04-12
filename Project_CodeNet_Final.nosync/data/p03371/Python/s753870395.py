A, B, C, X, Y = map(int, input().split())
ans = float('inf')
for i in range(0, 10**5+1):
    res = 2 * C * i + max(0, X - i) * A + max(0, Y - i) * B
    if res < ans:
        ans = res
print(ans)