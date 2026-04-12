N = int(input())
S = input()
K = int(input())

remaining = S[K-1]
T = ''
for i in range(N):
    if S[i] == S[K-1]:
        T = T + S[i]
    else:
        T = T + '*'

print(T)
