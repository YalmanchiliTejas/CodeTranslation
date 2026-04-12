n=int(input())
a=map(int,raw_input().split(' '))
n=len(a)
ans=0
while 1 :
    k=0
    for i in xrange(1,n) :
        if a[i]>a[k] :
            k=i
    if a[k]<n :
        break
    t=a[k]/n
    ans+=t
    for i in xrange(n) :
        a[i]+=t
    a[k]-=t*(n+1)

print ans
