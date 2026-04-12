N =int(input())
S = list(input())
K = int(input())
key = S[K-1]

for i in range(N):
    if S[i]!=key:
        S[i]='*'
print(''.join(S))