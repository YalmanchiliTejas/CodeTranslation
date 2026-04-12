a=input()
b=input().split()
N=int(a)
c=[]
ans=0
for i in range(N):
    c.append(int(b[i]))
s=sum(c)
for i in range(N):
    s=s-c[i]
    ans+=c[i]*s
print(ans%1000000007)