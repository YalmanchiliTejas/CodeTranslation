from sys import stdin
N, M = [int(i) for i in stdin.readline().rstrip().split()]
if N == M:
    print("Yes")
else:
    print("No")