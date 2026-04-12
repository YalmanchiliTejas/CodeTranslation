import sys
stdin = sys.stdin
mod = 10**9 + 7

ns = lambda: stdin.readline().rstrip()
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
sa = lambda h: [list(map(int, stdin.readline().split())) for i in range(h)]

x, y, z = na()

print((x-z)//(y+z))