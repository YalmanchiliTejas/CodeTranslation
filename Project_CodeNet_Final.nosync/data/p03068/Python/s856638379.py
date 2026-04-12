N = int(input())
S = list(input())
K = int(input())
for i,s in enumerate(S):
    if s!=S[K-1]:
        S[i]='*'
print(''.join(S))