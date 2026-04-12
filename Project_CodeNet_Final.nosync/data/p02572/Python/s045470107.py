import sys
input=sys.stdin.readline

n=int(input())
a=list(map(int,input().split()))

INF=10**9+7

s=0
for i in a:
    s=(s+i)%INF

d=0
for i in a:
    d=(d+i**2)%INF

ans=(s**2-d)%INF

def modinv(a,m):
    b=m
    (x,lastx)=(0,1)
    (y,lasty)=(1,0)
    while not b==0:
        q=a//b
        (a,b)=(b,a%b)
        (x, lastx) = (lastx - q * x, x)
        (y, lasty) = (lasty - q * y, y)
    return lastx%m
ans=(ans*modinv(2,INF))%INF

print(ans)