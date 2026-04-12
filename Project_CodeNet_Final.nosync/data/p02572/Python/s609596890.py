#!/usr/bin/env python3
import sys
import itertools

def main():
    input = sys.stdin.readline
    mod = 10 ** 9 + 7
    n = int(input())
    a = list(map(int, input().split()))
    b = list(itertools.accumulate(a))

    ans = 0
    for i in range(n):
        ans += (a[i] * (b[-1] - b[i]) % mod)
        ans %= mod
        
    print(ans)


if __name__ == '__main__':
    main()
