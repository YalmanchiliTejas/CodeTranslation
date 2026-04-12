from bisect import*
n,*a=map(int,open(0))
b=[-1]*n
for a in a:b[bisect(b,a-1)-1]=a
print(n-b.count(-1))