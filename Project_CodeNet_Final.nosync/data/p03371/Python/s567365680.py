a, b, c, x, y = map(int, input().split())
c = 2 * c
ans = 1001001001
for i in range(max(x, y) + 1):
    tmp = a * max(0, x - i) + b * max(0, y - i) + c * i
    ans = min(ans, tmp)
print(ans)
