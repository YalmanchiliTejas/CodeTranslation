n=int(input())
s=list(input())
k=int(input())

tg=s[k-1]

for i in range(n):
    if s[i] != tg:
        s[i]='*'

print(''.join(s))

