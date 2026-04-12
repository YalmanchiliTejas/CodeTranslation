import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))

mass = [0]*(N+1)
for i in range(N):
    mass[i+1] = mass[i] + A[i]

answer = 0
for i in range(N-1):
    answer += (A[i]*(mass[N]-mass[i+1]))


print(answer % (10**9 + 7))