def deque(a):
    n = len(a)
    cur = [(x, 0) for x in a]
    nxt = [(0, 0)] * n
    for l in range(2, n + 1):
        for i in range(n - l + 1):
            j = i + l - 1
            x, y = cur[i]
            z, t = cur[i + 1]
            if a[i] + t - z > a[j] + y - x:
                nxt[i] = (a[i] + t, z)
            else:
                nxt[i] = (a[j] + y, x)
        cur, nxt = nxt, cur
    return cur[0][0] - cur[0][1]


def main():
    input()  # n
    a = [int(x) for x in input().split()]
    return deque(a)


print(main())
