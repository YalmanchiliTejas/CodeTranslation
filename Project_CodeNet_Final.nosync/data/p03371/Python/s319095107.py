#!/usr/bin/env python
import math

def main():
    A, B, C, X, Y = map(int, input().split())
    ans = float("inf")
    for k in range(2 * max(X, Y) + 1):
        i = max(0, math.ceil(X - 0.5 * k))
        j = max(0, math.ceil(Y - 0.5 * k))
        total = A * i + B * j + C * k
        if ans > total:
            ans = total
    print(ans)

if __name__ == '__main__':
    main()