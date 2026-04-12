N=int(input())
S=input()
K=int(input())
re=S[K-1]
for i in range(N):
    if(S[i]!=re):
        S=S[:i]+'*'+S[i+1:]
print(S)