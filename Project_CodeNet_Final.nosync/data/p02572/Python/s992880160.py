n=int(input())
l=list(map(int,input().split()))
s=sum(l)
ss=s**2
c=0
for i in range(n):
    c+=(l[i]*l[i])
p=(ss-c)//2
print(p%1000000007)

