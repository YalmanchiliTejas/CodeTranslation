a, b, c, x, y = map(int, input().split())

cmx = max(x, y)*2

ans = 10**9+7
for cn in range(cmx+1):
    an = max(0, x - cn//2)
    bn = max(0, y - cn//2)
    total = an*a + bn*b + cn*c
    ans = min(ans, total)

print(ans)