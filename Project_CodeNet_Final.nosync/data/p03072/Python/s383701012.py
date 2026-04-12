
N = int(input())
H = list(map(int, input().split()))

M = [0] * (N+1)

SUM = 0
for i in range(0, N):
    M[i+1] = max(M[i], H[i])
    if M[i] <= H[i]:
        SUM += 1

print(SUM)
