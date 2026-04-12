n=int(input())
a=input()
a=[int(n) for n in a.split()]
c=0
aa=sum(a)
for i in range(n):
    aa-=a[i]
    c+=a[i]*aa
    c=c%(10**9+7)
print(c)