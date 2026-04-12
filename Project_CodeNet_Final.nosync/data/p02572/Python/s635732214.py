#!/usr/bin/env python
# coding: utf-8

def ri():
    return int(input())

def rl():
    return list(input().split())

def rli():
    return list(map(int, input().split()))

def main():
    n = ri()
    la = rli()
    su = sum(la)
    ans = 0
    mod = 10**9+7
    for a in la:
        su -= a
        ans += su*a
        ans %= mod
    print(ans)


if __name__ == '__main__':
    main()
