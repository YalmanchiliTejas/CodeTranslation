#import math
#import bisect
#import numpy as np
import sys
input = sys.stdin.readline
MOD = 10**9 + 7
INF = float('INF')

def main():
    a, b, c, x, y = list(map(int,input().split()))

    cm = 2 * max(x, y)
    ans = INF

    for cbuy in range(cm+1):
        xbuy = max(0, x - (cbuy//2))
        ybuy = max(0, y - (cbuy//2))
        price = xbuy * a + ybuy * b + cbuy * c
        ans = min(ans, price)

    print(ans)

if __name__ == '__main__':
    main()