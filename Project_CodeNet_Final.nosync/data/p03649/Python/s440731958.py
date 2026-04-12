n=int(input())+1;a=list(map(int,input().split()));d,A,q=[0]*n,0,0
for i in range(n-1):
    q+=(a[i]+1)//n;d[(a[i]+1)%n]+=1
A=q*n
for r in range(1,n):
    q+=d[n-r]-1;A=min(A,max(q,0)*n+r)
print(A)