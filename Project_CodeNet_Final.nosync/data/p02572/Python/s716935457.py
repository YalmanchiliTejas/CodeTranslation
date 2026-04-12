from itertools import accumulate
n=int(input())
a=list(map(int, input().split()))
acc = list(accumulate(a[::-1]))[::-1]
ans=0
for i in range(n-1):
    ans+=a[i]*acc[i+1]
    ans%=10**9+7
print(ans)