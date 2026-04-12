a, b, c, x, y = map(int, input().split())
n = max(x, y)
ans = float('inf')
for i in range(n + 1):
    buyab = i * c * 2
    buya = max((x - i), 0) * a
    buyb = max((y - i), 0) * b
    sum = buyab + buya + buyb
    ans = min(ans, sum)
print(ans)