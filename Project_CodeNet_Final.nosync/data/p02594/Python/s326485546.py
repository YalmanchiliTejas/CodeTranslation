from sys import stdin
from sys import setrecursionlimit
setrecursionlimit(10 ** 7)

n = int(stdin.readline().rstrip())

if n >= 30:
    print("Yes")
else:
    print("No")