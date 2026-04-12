n,a=open(0);n=int(n)+1;d,A,q=[0]*n+[1],1e+18,0
for b in a.split():b=int(b);q+=(b+1)//n;d[(b+1)%n]+=1
for r in range(n):q+=d[n-r]-1;A=min(A,max(q,0)*n+r)
print(A)