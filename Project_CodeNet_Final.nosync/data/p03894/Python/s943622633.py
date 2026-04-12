j=lambda:map(int,raw_input().split())
n,q=j()
u=1
c=[1]*3+[0]*(n-2)+[1]
for p in[-1]*q:a,b=d=j();u+=u in d and a+b-2*u;c[a],c[b]=c[b],c[a];c[u-1]=c[u+1]=1
print sum(c)-2