n=int(input())
l=list(input())
k=int(input())
s=l[k-1]
for i in range(n):
    if(l[i]!=s):
        l[i]='*'
print(''.join(l))
