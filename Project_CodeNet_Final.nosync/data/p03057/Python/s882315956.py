p=int(1e9+7)
def calc(n,l,r):
    f=[0]* (n+1)
    f[0]=1
    sum=0
    for i in range (1,n+1):
        if i>=l:
            sum+=f[i-l]
        f[i]=sum%p
        if (i>=r):
            sum-=f[i-r]
    ans=0
    for i in range (l,r+1):
        ans=(ans+f[n-i]*i)%p
    return ans

n,m=input().split()
n=int(n)
m=int(m)
s=input()
a=s.split(chr(ord('R')+ord('B')-ord(s[0])))
if len(a)==1:
    print((calc(n,2,n)+1)%p)
elif n%2==1:
    print(0)
else:
    r=len(a[0])+1-len(a[0])%2
    for i in range(1,len(a)-1):
        if len(a[i])%2==1 :
            r=min(r,len(a[i]));
    n=n//2
    r=(r+1)//2
    print(calc(n,1,r)*2%p)
