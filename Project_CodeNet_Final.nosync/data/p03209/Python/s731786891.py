#!/usr/bin/env python3

n, x = list(map(int, input().split()))

a, p = [1], [1]
for i in range(n):
    a.append(a[i]*2+3)
    p.append(p[i]*2+1)


def calc(N, X):
    if X == 1:
        if N == 0:
            return 1
        else:
            return 0
    elif X <= 1+a[N-1]:
        return calc(N-1, X-1)
    elif X == 2+a[N-1]:
        return p[N-1]+1
    elif X <= 2*a[N-1]+2:
        return p[N-1]+1+calc(N-1, X-2-a[N-1])
    elif X == 2*a[N-1]+3:
        return 2*p[N-1]+1
    else:
        raise("Error")


print(calc(n, x))
