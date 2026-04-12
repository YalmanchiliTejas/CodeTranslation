from functools import lru_cache
N, X = map(int, input().split())
a = [0] * (N)
p = [0] * N
a[0] = 1
p[0] = 1
for i in range(1, N):
    a[i] = a[i-1]*2 + 3
    p[i] = p[i-1]*2 + 1
@lru_cache(maxsize=1000)
def f(n, x):
    if n == 0 and x == 0:
        return 0
    elif n == 0:
        return 1
    if x == 1:
        return 0
    elif x<=1+a[n-1]:
        return f(n-1, x-1)
    elif x == 2+a[n-1]:
        return p[n-1]+1
    elif x <= 2+2*a[n-1]:
        return p[n-1]+1+f(n-1, x-2-a[n-1])
    else:
        return 2*p[n-1]+1
print(f(N, X))