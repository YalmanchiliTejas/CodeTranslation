def eat(x,n):
    ans,p = 0,0
    while(n>=0 and x>0):
        p = 2**(n+1)-1
        if x>=p:
            x-=p
            ans+=int((p+1)/2)
        else:
            x-=1
        n-=1
    return ans

if __name__ == '__main__':
    n,x=map(int, input().split())
    p = 2**(n+1)-1
    if x<n:
        print(0)
    elif x>=2*p-n-1:
        print(p)
    else:
        print(int(eat(x,n)))

