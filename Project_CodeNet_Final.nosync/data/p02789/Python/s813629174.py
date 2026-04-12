# !/usr/nbin/python3

"""
https://atcoder.jp/contests/abc152/tasks/abc152_a
AC or WA.
"""

def solve(n, m):
    if n == m: print("Yes")
    else: print("No")

if __name__ == "__main__":
    n, m = list(map(int, input().split()))

    solve(n, m)
