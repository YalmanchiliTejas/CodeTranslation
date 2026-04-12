from sys import stdin

n,m = [int(x) for x in stdin.readline().rstrip().split()]

if n == m:
    print("Yes")
else:
    print("No")
