n=int(input())
l=list(map(int,input().split()))
a=list(l)
l.reverse()
for i in range(1,n):
    l[i]=l[i]+l[i-1]
c=0
l.reverse()
for i in range(n-1):
    c+=(a[i]*l[i+1])%((10**9)+7)
c=c%((10**9)+7)
print(c)
    