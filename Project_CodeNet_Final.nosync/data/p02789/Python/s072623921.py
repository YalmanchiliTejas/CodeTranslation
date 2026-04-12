from sys import stdin

A, B= [int(x) for x in stdin.readline().rstrip().split()]
if A == B:
    print('Yes')
else:
    print('No')