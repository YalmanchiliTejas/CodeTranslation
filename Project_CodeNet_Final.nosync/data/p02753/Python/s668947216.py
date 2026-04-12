import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline().rstrip()  # ignore trailing spaces

s = ns()

if s == "AAA" or s == "BBB":
    print("No")
else:
    print("Yes")
