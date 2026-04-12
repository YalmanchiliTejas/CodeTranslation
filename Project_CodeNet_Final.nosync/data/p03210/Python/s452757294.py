import sys

stdin = sys.stdin

ni = lambda: int(ns())
ns = lambda: stdin.readline().rstrip()
na = lambda: list(map(int, stdin.readline().split()))

# code here
X = ni()

print('YES' if X in [3, 5, 7] else 'NO')