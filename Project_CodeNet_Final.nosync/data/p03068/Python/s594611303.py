N = int(input())
S = list(input())
K = int(input())
a = S[K-1]
T=[]

for i in range(N):
    if S[i] != a:
        S[i] = '*'

T = ''.join(S)

print(T)