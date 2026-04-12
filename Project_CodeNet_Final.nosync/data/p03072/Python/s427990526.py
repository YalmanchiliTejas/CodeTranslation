import numpy as np
import math
import collections
import fractions
import itertools

def solve():
    n = int(input())
    h = list(map(int, input().split()))
    m = h[0]
    ans = 0
    for i in range(1,n):
        if h[i] >= m:
            ans += 1
            m = h[i]
    print(ans+1)
    return 0

if __name__ == '__main__':
    solve()