mod=1000000007
n=int(input())
a=list(map(int,input().split()))

s1=0
for i in range(0,n):
    s1+=a[i]

s3=s1*s1

s2=0
for i in range(0,n):
    s2+=(a[i]*a[i])

print (((s3-s2)//2)%mod)
