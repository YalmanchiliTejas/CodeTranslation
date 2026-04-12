import sys
import copy
from collections import deque
import collections
stdin = sys.stdin

mod = 10**9+7

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline().rstrip()  # ignore trailing spaces

x = ni()

if x>=30:
    print("Yes")
else:
    print("No")


