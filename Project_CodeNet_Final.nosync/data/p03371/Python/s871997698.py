a, b, c, x, y = map(int, input().split())
ans = 10**18
for i in range(500000):
    ans = min(ans, i*c + max(0,x - i//2)*a + max(0,y - i//2)*b)
print(ans)