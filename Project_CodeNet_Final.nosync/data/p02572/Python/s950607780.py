import itertools as itr
MOD=pow(10,9)+7

N=int(input())

A=list(map(int, input().split()))
sumA = list(itr.accumulate(A))
ans=0
for i in range(len(A)-1):
    a=A[i+1]
    b=sumA[i]
    ans=(ans+a*b%MOD)%MOD

print(ans)