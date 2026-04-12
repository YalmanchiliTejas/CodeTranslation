import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))

d = 1000000000 + 7

s = 0

sum_list = [A[0]]
for a in A[1:]:
    sum_list.append(a + sum_list[-1])
for i in range(N):
    s += A[i] * (sum_list[N-1] - sum_list[i])
print(s % d)