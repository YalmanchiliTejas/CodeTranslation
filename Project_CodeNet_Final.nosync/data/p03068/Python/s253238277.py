N = int(input())
S = input()
K = int(input())


ch = S[K-1]

for i in range(N):
    if S[i] != ch and S[i] != '*':
        S =S.replace(S[i],'*')

print(S)
