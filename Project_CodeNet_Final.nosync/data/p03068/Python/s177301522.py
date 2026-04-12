N = int(input())
S = str(input())
K = int(input())

T = ''
for i in range(0, N):
    if S[i] != S[K-1]:
        T += '*'
    else:
        T += S[i]
print(T)