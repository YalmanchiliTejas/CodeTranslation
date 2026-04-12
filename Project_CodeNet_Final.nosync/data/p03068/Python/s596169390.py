N = int(input())
S = input()
K = int(input())

x = S[K-1]
T = [S[i] for i in range(N)]
for i in range(N):
    if T[i] != x:
        T[i] = '*'

y = ''
for i in range(N):
    y += T[i]

print(y)