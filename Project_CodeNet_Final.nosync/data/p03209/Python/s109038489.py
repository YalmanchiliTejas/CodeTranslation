n, x = map(int, input().split())
pty = [[] for i in range(n + 1)]
lay = [[] for i in range(n + 1)]
pty[0] = 1
lay[0] = 1
for L in range(1, n + 1):
    pty[L] = 2 * pty[L - 1] + 1
    lay[L] = 2 * lay[L - 1 ] + 3
ans = 0
while x > 0:
    if x >= lay[L] + 1:
        x -= lay[L] + 1
        ans += pty[L] + 1
    elif x == lay[L]:
        x -= lay[L]
        ans += pty[L]
    else:
        L -= 1
        x -= 1
print(ans)