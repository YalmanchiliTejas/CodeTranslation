N=int(input())
S=list(input())
K=int(input())
w=S[K-1]
for i in range(N):
    if S[i]!=w:
        S[i]='*'
print(''.join(S))