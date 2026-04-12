N = int(input())
A = [int(a) for a in input().split(' ')]
S = [0] * N
s = 0

S[N - 1] = A[N - 1]
for i in range(N - 2, -1, -1):
    S[i] = S[i + 1] + A[i]


for i in range(N - 1):
    s += A[i] * S[i + 1]
    s = s % 1000000007

print(s)
