N=int(input())
S=input()

S=list(S)

K=int(input())

for i in range(N):
    if not S[i]==S[K-1]:
        S[i]='*'

S=''.join(S)

print(S)
