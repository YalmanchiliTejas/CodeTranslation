n=int(input())
a=list(map(int,input().split()))
l=list(map(lambda z:z**2,a))
x=sum(a)**2
y=sum(l)
t=(x-y)//2
if t>(10**9+7):
       print(t%(10**9+7))
else:
       print(t)
