import sys
from collections import deque
stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline().rstrip()  # ignore trailing spaces

n = ni()
if n == 3 or n == 5 or n == 7:
    print("YES")
else:
    print("NO")