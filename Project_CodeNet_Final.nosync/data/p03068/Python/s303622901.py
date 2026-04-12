N=int(input())
S=input()
s=list(S)
K=int(input())

x=s[K-1]

for i in range(N):
    if s[i]!=x:
        s[i]="*"

moji=''.join(s)
print(moji)