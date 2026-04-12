def main():
    N, X = map(int, input().split())
    p = [1]
    for i in range(N+1):
        p.append(p[-1] * 2 + 1)
    a = [1]
    for i in range(N+1):
        a.append(a[-1]*2 + 3)

    return helper(N, X, a, p)

def helper(N, X, a, p):
    if N == 0:
        return 1
    if X == 1:
        return 0
    elif X <= a[N-1] + 1:
        return helper(N-1, X-1, a, p)
    elif X == a[N-1] + 2:
        return p[N-1] + 1
    elif X <= 2*a[N-1] + 2:
        return p[N-1] + 1 + helper(N-1, X-a[N-1]-2, a, p)
    else:
        return 2*p[N-1] + 1

if __name__ == '__main__':
    print(main())