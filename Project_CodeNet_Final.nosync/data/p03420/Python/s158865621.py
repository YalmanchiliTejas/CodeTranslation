def calc0(N, K):
    r = 0
    for a in range(1, N + 1):
        for b in range(1, N + 1):
            if a % b >= K:
                print(a, b, a % b)
                r += 1
    return r

def calc1(N, K):
    result = 0
    for i in range(K, N):
        for x in range(i + 1, N + 1):
            if i > 0:
                r = (N + x - i) // x
            else:
                r = (N + x - i) // x - 1
            # print(i, x, r)
            result += r
    return result

def calc2(N, K):
    if K == 0:
        return N**2
    result = 0
    for x in range(1, N + 1):
        for i in range(K, min(N, x)):
            r = (N - i) // x + 1
            result += r
    return result

def calc2(N, K):
    if K == 0:
        return N**2
    result = 0
    for x in range(1, N + 1):
        for i in range(K, min(N, x)):
            r = (N - i) // x + 1
            result += r
    return result

def calc3(N, K):
    if K == 0:
        return N**2
    result = 0
    for x in range(1, N + 1):
        st = N - min(N, x) + 1
        ed = N - K
        if (ed < x):
            r = (ed - st + 1)
        else:
            r = 0
            for j in range(st, ed + 1):
                r += j // x + 1
        print(st, ed, x, r)
        result += r
    return result

def calc(N, K):
    if K == 0:
        return N**2
    result = 0
    for b in range(1, N + 1):
        if b <= K:
            continue
        n, m = divmod(N, b)
        r1 = (b - K) * n
        r2 = 0
        if m >= K:
            r2 = m - K + 1
        result += r1 + r2
    return result

N, K = [int(_) for _ in input().split()]
# print(calc2(N, K))
print(calc(N, K))
