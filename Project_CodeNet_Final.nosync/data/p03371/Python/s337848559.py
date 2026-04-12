a, b, c, x, y = map(int, input().split())

# i組みのabを買うことについて全探索
ans = float("inf")
for i in range(max(x, y)+1):
    price = i * 2 * c + max(x-i, 0) * a + max(y-i, 0) * b
    ans = min(ans, price)
print(ans)
