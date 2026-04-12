N=int(input())
S=str(input())
K=int(input())
Slist = list(S)
S_changed= S
for i in range(N):
    if S[K-1]!=S[i]:
        Slist[i]='*'
        S_changed="".join(Slist)
print(S_changed)
