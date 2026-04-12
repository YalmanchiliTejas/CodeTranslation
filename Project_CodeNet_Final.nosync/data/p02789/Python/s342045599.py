#!/usr/bin/env python3

import sys

def solve(n, m):
    return n == m

def main():
    n, m = [int(s) for s in sys.stdin.readline().split()]

    ans = solve(n, m)

    print("Yes" if ans else "No")

if __name__ == '__main__':
    main()
