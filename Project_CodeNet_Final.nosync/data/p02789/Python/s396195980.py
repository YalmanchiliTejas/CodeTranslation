import sys

sys.setrecursionlimit(1000000)
input = lambda : sys.stdin.readline().rstrip()

N, M = input().split()
if N == M:
    print("Yes")
else:
    print("No")
