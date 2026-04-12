import sys

n,k=map(int,input().split())

if k==0:
    print(n*n)
    sys.exit()

s=0
for b in range(k+1,n+1):
    sb=0
    sb+=(n//b)*(b-k)
    c=n%b
    if c>=k:
        sb+=c-k+1
    s+=sb

print(s)
