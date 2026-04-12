import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

N,M = map(int,read().split())

answer = 'Yes' if N == M else 'No'
print(answer)