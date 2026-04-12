import sys
stdin = sys.stdin
 
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
nn = lambda: list(stdin.readline().split())
ns = lambda: stdin.readline().rstrip()

n = ni()
a = na()

b = 0
c = 0
for i in a:
    if b <= i:
        b = i
        c += 1

print(c)