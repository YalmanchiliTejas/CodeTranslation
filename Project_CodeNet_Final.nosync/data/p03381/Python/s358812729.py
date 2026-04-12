n,*x=map(int,open(0).read().split())
y=sorted(x)[n//2-1:n//2+1]
for i in x:print(y[i<=y[0]])