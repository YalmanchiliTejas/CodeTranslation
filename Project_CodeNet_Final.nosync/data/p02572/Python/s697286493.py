import sys

input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))

A_sum_s = sum(A) ** 2

for e in A:
    A_sum_s -= e ** 2
print(A_sum_s // 2 % (10**9 + 7))