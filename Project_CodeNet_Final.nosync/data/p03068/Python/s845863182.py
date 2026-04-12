n=int(input())
s=list(input())
k=int(input())

X=s[k-1]

for i in range(n):
    if s[i]!=X:
        s[i]='*'

print(''.join(s))