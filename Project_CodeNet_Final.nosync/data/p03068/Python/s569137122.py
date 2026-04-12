N = int(input())
S = list(input())
K = int(input())
sk = S[K - 1]
A = ''
for i in range(N):
    if S[i] != sk:
        S[i] = '*'
for i in range(N):
    A = A + S[i]
print(A)
