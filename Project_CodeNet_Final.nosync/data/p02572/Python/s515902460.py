mod=1000000007
n=int(input())
x=list(map(int,input().split()))
cl=[1]
for i in range(1,n):
    cl.append(cl[i-1]+x[i])
sum=0
for i in range(n-1):
    sum+= x[i]*(cl[n-1]-cl[i])
    sum%=mod

print(sum)
