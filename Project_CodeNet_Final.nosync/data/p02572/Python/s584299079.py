n=int(input())
a=list(map(int, input("").split()))
o=0
aa=[]
for i in a:
    aa.append(i**2)
s=sum(a)
o=(s**2-sum(aa))//2
o%=10**9+7
print(o)