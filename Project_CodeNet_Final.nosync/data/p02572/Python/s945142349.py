n=int(input()) 
a=[int(x) for x in input().split()] 
x=sum(a)**2 
y=sum([x**2 for x in a]) 
z=(x-y)//2 
mod=10**9+7
print(z%mod )