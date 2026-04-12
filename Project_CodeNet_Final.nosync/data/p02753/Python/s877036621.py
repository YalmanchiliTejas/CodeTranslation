import sys
stdin = sys.stdin
sys.setrecursionlimit(10**9)
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
nn = lambda: list(stdin.readline().split())
ns = lambda: stdin.readline().rstrip()

s = ns()
ss = list(s)
a = 'No' if ss[0] == ss[1] and ss[1] == ss[2] else 'Yes'
print(a)