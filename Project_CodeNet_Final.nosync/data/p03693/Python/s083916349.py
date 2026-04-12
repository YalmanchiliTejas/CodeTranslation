import sys
stdin = sys.stdin

mod = 10**9 + 7

ns = lambda: stdin.readline().rstrip()
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))

r, g, b = ns().split()
n = int(r+g+b)
print("YES" if n % 4 == 0 else "NO")