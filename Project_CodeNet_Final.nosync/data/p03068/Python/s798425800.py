N = int(input())
S = str(input())
K = int(input())

x = str(S[K-1])
T =""
for i in range(N):
    if S[i] != x:
        T += '*'
    else:
        T+=S[i]

print(T)
