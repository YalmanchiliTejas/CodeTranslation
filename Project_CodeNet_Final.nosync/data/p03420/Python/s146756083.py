n,k=map(int,input().split())
if k==0:
    print(n**2);exit()
def f(b):
    return (b-k)*(n//b)+max(0,1+n-(n//b)*b-k)
print(sum(f(i)for i in range(k+1,n+1)))
