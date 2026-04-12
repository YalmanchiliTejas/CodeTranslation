a, b, c, x, y = [int(i) for i in input().split()]
ans = 10**18
for i in range(max(x, y)*2 + 1):
    ans = min(ans, c * i + max(0,(x - i//2)) * a + max(0,(y - i//2)) * b)
print(ans)
