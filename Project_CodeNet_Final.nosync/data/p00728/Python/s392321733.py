import sys
while 1:
    n=int(input())
    if n==0:
        sys.exit()
    l=[0]*n
    ma=0
    mi=1000
    s=0
    for i in range(n):
        l[i]=int(input())
        s+=l[i]
        if l[i]>ma:
            ma=l[i]
        if l[i]<mi:
            mi=l[i]
        
    print ((s-ma-mi)//(n-2))