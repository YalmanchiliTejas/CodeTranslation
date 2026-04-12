n,x=map(int,input().split())

def p(n,x):
    if x<=n:
        return 0
    if n==0:
        return 1
    i=0
    while 2**(2+i)-3+n-i<=x:
        i+=1
    if 2**(i+1)-2+n-i==x:
        return 2**i-1
    else:
        return 2**i+p(i-1,x-(2**(i+1)+n-i-2)-1)

print(p(n,x))
