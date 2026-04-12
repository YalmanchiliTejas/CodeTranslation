def resolve():
    import bisect
    n = int(input())
    a = [int(input()) for _ in range(n)]
    m = []
    for i in range(n-1, -1, -1):
        if i == n-1:
            m.append(a[i])
        else:
            if m[-1] <= a[i]:
                m.append(a[i])
            else:
                j = bisect.bisect_right(m, a[i])
                m[j] = a[i]
    print(len(m))

resolve()