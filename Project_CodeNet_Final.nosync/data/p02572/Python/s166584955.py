from itertools import accumulate
N=int(input())
A=list(map(int,input().split()))
p=10**9+7
ans=0
B=list(accumulate(A[::-1]))
for i,value in enumerate(A):
    if i==(N-1):
        break
    ans+=((value%p)*(B[-2-i]%p))%p
    ans=ans%p
print(ans)