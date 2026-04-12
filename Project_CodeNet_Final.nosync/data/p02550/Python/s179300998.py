n,x,m=map(int,input().split())
A=dict()
i=0
y=x
while True:
    if not(y in A.keys()):
        A[y]=i
        i+=1
        y=(y**2)%m
    else:
        break
j=A[y]
#print(A)
#print(i)
#print(j)
A=list(sorted(A.items(),key=lambda x:x[1]))
#print(A)
s=0
for k in range(j):
    s+=A[k][0]
p=(n-j)//(i-j)
q=(n-j)%(i-j)
t=0
for k in range(j,i):
    t+=A[k][0]
u=0
if q!=0:
    for k in range(j,j+q):
        u+=A[k][0]
else:
    u=0
print(s+t*p+u)            