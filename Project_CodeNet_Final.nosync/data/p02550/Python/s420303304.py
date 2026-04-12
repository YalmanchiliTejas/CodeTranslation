import sys
INF = 1 << 60
MOD = 10**9 + 7 # 998244353
sys.setrecursionlimit(2147483647)
input = lambda:sys.stdin.readline().rstrip()
def resolve():
    n, x, m = map(int, input().split())
    ans = 0

    # pigeon hole principle
    index = [-1] * m
    now = x
    i = 0
    while index[now] == -1:
        index[now] = i
        i += 1
        ans += now
        now = now * now % m
        n -= 1
        if n == 0:
            print(ans)
            return

    l = i - index[now]
    cycle = 0
    for _ in range(l):
        cycle += now
        now = now * now % m

    q, r = divmod(n, l)
    ans += q * cycle

    for _ in range(r):
        ans += now
        now = now * now % m

    print(ans)
resolve()