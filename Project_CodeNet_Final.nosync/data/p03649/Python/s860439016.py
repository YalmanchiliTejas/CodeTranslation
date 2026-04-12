#!/usr/bin/env python3


def solve(n, a):

    c = [ai // (n + 1) for ai in a]
    r = sum(c)
    b = [a[i] + r - (n + 1) * c[i] for i in range(n)]
    ans = r

    min_b = min(b)
    if n < min_b:
        r = min_b - n
        b = [bi - r for bi in b]
        ans += r * n

    while True:
        max_b = -1
        j = -1
        for i in range(n):
            if max_b < b[i]:
                max_b = b[i]
                j = i
        if max_b < n:
            break
        ans += 1
        b[j] -= n + 1
        for i in range(n):
            b[i] += 1

    return ans


def main():
    n = input()
    n = int(n)
    a = list(map(int, input().split()))

    print(solve(n, a))


if __name__ == '__main__':
    main()

