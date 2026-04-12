a, b, c, x, y = map(int, input().split())

ans = float("inf")
for i in range(200000):
    tmp = 0
    tmp += c * i * 2
    if x - i>0:
        tmp += a *(x-i)
    if y - i>0:
        tmp += b *(y-i)
    ans = min(ans, tmp)
print(ans)