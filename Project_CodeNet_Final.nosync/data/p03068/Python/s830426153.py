N,S,K = (input() for T in range(0,3))
N,K = int(N),int(K)
D = ['*']*N
for TN in range(0,N):
    if S[TN]==S[K-1]:
        D[TN] = S[K-1]
print(''.join(D))