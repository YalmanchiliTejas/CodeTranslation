mod = 10**9 + 7
def solve():
    n = int(input())
    a = list(map(int, input().split()))
    s = 0
    ans = 0
    for i in range(n):
        ans = (ans + s * a[i]) % mod
        s += a[i]
    print(ans)
t = 1
while t > 0:
    solve()
    t -= 1