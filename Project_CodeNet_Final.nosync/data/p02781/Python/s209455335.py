import sys
sys.setrecursionlimit(303)


def doit(n, k, m):
    if len(n) == 0 or k < 0:
        return k == 0
    if (n, k) not in m:
        d = int(n[0])
        m[(n, k)] = sum(doit(n[1:] if i == d else '9' * (len(n) - 1), k - 1 if i > 0 else k, m) for i in range(d + 1))
    return m[(n, k)]


print(doit(input(), int(input()), {}))
