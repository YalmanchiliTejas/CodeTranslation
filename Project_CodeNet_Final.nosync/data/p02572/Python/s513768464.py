n=int(input())
a=[int(i) for i in input().split()]
d=sum(a)**2
e=0
for i in range(0,len(a)):
    e=e+(a[i]*a[i])
print(((d-e)//2)%1000000007)