N=int(input())
S=list(input())
Kkari=int(input())
K=Kkari-1
t=0
while t<N:
    if S[t]!=S[K]:
        S[t]='*'
    t=t+1
print(''.join(S))
