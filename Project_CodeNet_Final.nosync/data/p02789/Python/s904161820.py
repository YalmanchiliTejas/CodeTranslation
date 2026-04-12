import sys
input = sys.stdin.readline

N, M = map(int, input().split())
print('Yes') if N == M else print('No')