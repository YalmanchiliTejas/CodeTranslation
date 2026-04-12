n=int(input())
a=list(map(int,input().strip().split()))[:n]
E=sum(a)**2
s=0
s=sum(i*i for i in a)
print(((E-s)//2)%(10**9+7))