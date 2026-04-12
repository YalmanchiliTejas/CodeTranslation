# 2019/10/02

n,k=map(int,input().split())

cnt=0
if k==0:
    print(n**2)
    exit()
for b in range(k+1,n+1):
    r=(n+1)%b
    p=(n+1)//b
    cnt+=p*(b-k)
    cnt+=max(r-k,0)
print(cnt)