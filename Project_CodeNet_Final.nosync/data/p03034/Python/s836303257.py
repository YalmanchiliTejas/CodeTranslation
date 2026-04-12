from collections import defaultdict
N = int(input())
*S, = map(int, input().split())

ans = 0
c = 0
memo = defaultdict(int)
for a in range(N-1, 0, -1):
    d = 1
    m = min(N-1-a, a*a)
    while d*d <= m:
        if (N-1-a) % d == 0:
            e = (N-1-a) // d
            if a > d and (a % d > 0 or N-1 < 2*a):
                memo[a, d] = s = memo[a+d, d] + S[a] + S[N-1-a]
                ans = max(ans, s)
            if a > e and (a % e > 0 or N-1 < 2*a):
                k = (N-1-a) // e
                memo[a, e] = s = memo[a+e, e] + S[a] + S[N-1-a]
                ans = max(ans, s)
        d += 1
print(ans)