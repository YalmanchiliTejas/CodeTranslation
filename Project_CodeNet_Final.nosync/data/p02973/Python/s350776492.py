import bisect

n = int(input())
a = [ int(input()) for _ in range(n) ]

ans = [-1] * n
for b in a:
    ans[bisect.bisect(ans, b-1) - 1] = b

print(n - bisect.bisect(ans, -1))
