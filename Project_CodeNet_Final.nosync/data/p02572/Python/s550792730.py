import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
mod = int(1e9+7)

sum = 0
row = 0
for ii in range(N-1):
    i = N-2-ii
    row += A[i+1]
    row %= mod
    sum += A[i] * row
    sum %= mod

print(sum)