import sys
while 1:
    n=int(input())
    if n==0:
        sys.exit()
    ma=0
    mi=1000
    s=0
    for i in range(n):
        l=int(input())
        s+=l
        if l>ma:
            ma=l
        if l<mi:
            mi=l
        
    print ((s-ma-mi)//(n-2))