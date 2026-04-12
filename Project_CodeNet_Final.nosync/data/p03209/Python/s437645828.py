# tokenakatta ...
def main():
    N, X = map(int, input().split())
    a, p = [1],[1]
    for i in range(N):
        a.append(a[i] * 2 + 3)
        p.append(p[i] * 2 + 1)
    return bur(N, X, a, p)
def bur(N, X, a, p):
    if N == 0:
        return 0 if X <= 0 else 1
    elif X == 1:
        return 0
    elif X <= 1 + a[N-1]:
        return bur(N-1, X-1, a, p)
    elif X == 2 + a[N-1]:
        return p[N-1] + 1
    elif X <= 2 + 2 * a[N-1]:
        return p[N-1] + 1 + bur(N-1, X-2-a[N-1], a, p)
    else:
        return 2 * p[N-1] + 1
print(main())
