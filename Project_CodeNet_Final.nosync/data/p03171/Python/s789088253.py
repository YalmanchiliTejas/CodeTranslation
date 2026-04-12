def deque(a):
    n = len(a)
    cur = a[:]
    nxt = [0] * (n - 1)
    for l in range(2, n + 1):
        for i in range(n - l + 1):
            j = i + l - 1
            nxt[i] = max(a[i] - cur[i + 1], a[j] - cur[i])
        cur, nxt = nxt, cur
    return cur[0]


def main():
    input()  # n
    a = [int(x) for x in input().split()]
    return deque(a)


print(main())
