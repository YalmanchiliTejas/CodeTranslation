N=int(input())
S=list(input())
K=int(input())
word=S[K-1]
for i in range(len(S)):
    if S[i]!=word:
        S[i]='*'
print(''.join(S))
