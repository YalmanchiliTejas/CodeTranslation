import sys

r1, r2 = list(map(int, sys.stdin.readline().strip().split(" ")))

R = 1/r1 + 1/r2

print(1/R)