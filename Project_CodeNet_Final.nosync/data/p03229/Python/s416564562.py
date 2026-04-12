#!/usr/bin python3
# -*- coding: utf-8 -*-

from collections import deque

def main():
    N = int(input())
    A = [int(input()) for _ in range(N)]
    A.sort()
    A = deque(A)

    lnow = A.pop()
    rnow = lnow
    ret = 0
    while len(A)>0:
        lnxt = A[0]
        rnxt = A[-1]
        ll = abs(lnow - lnxt)
        rl = abs(rnow - lnxt)
        lr = abs(lnow - rnxt)
        rr = abs(rnow - rnxt)
        mx = max(ll, rl, lr, rr)
        ret += mx
        if mx == ll:
            lnow = lnxt
            x = A.popleft()
        elif  mx == rl:
            rnow = lnxt
            x = A.popleft()
        elif  mx == lr:
            lnow = rnxt
            x = A.pop()
        elif  mx == rr:
            rnow = rnxt
            x = A.pop()

    print(ret)


if __name__ == '__main__':
    main()