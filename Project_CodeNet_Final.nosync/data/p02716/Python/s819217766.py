n,*l=map(int,open(0).read().split());p=[0]*n;d=p[:]
for i,l in enumerate(l):p[i]=l+p[i-2];d[i]=max(l+d[i-2],[d,p][i&1][i-1])
print(d[-1])