a=int(input())
b=input()
c=int(input())
b=list(b)
l=b[c-1]
r=[i for i, x in enumerate(b) if x==l]
s=['*']*a
for k in r:
    s[k]=b[k]
print(''.join(s))