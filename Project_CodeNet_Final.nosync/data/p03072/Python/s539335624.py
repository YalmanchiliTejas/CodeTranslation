#!/usr/bin/env python3


def solv(n, h):
    top = 0
    ans = 0
    for hi in h:
        if top <= hi:
            top = hi
            ans += 1
    return ans


if __name__ == '__main__':

    n = int(input())
    h = map(int, input().split())

    ans = solv(n, h)

    print(ans)
