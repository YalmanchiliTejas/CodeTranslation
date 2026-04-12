N=int(input())
S=input()
K=int(input())
t=S[K-1]
for i in range(N):
    if S[i]!=t:
        S=S[:i]+'*'+S[i+1:]
print(S)