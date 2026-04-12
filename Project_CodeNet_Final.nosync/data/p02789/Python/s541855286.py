from sys import stdin
N, M = [int(_) for _ in stdin.readline().rstrip().split()]
print('Yes' if N == M else 'No')