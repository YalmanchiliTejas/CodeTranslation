n=int(input())
s=input()
S=list(s)
k=int(input())

for i in range(0,n):
    if S[i]==S[k-1]:
        continue
    else:
        S[i]='*'


print(''.join(S))