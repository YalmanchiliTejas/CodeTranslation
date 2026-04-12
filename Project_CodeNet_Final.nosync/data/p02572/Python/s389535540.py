import sys
n=int(input())
a=[int(i) for i in sys.stdin.readline().split()]
temps=[a[0]]+[0]*n

mod=1000000007
ans=0
for i in range(1,n):
    ans+=temps[i-1]*a[i]
    ans%=mod
    temps[i]=a[i]+temps[i-1]

print(ans)