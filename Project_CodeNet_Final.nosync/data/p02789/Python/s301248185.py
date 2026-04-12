from sys import stdin

N, M = [int(x) for x in stdin.readline().rstrip().split()]

if N == M:
    print("Yes")
else:
    print("No")

