import sys
stdin = sys.stdin
mod = 10**9 + 7

ns = lambda: stdin.readline().rstrip()
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
sa = lambda h: [list(map(int, stdin.readline().split())) for i in range(h)]

n = ni()
s = ns()
k = ni()


for i in s:
    if i == s[k-1]:
        print(i, end="")
    else:
        print("*", end="")
