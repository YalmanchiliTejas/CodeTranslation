N=int(input())
S=input()
K=int(input())

s=list(S)

for i in range(N):
    if s[K-1]!=s[i]:
        s[i]='*'

s_a=''.join(s)

print(s_a)
