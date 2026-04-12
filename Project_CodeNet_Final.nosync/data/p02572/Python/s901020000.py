N,*A=map(int,open(0).read().split())
l=[]
s=0
for a in reversed(A):
    s+=a
    l.append(s)
l.reverse()
m=1000000000+7
ans=0
for i in range(N-1):
    ans+=A[i]*l[i+1]
    ans%=m
print(ans)
