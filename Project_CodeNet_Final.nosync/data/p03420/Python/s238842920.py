n,k=map(int,input().split())
a=0
if k==0:
    print(n**2)
    exit()
for i in range(n):
    a+=max((n+1)//(i+1)*(i-k+1),0)+max((n+1)%(i+1)-k,0)
print(a)