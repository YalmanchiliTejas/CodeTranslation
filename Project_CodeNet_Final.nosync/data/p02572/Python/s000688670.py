# AtCoder Beginner Contest 177
# C - Sum of product of pairs

N= int(input())
ls= list(map(int,input().split()))

mod=10**9+7

ans=0
accumls=[0]

for i in range (N):
    accumls.append(accumls[-1]+ls[i])

for i in range (N-1):
    ans+= ls[i]*(accumls[-1]-accumls[i+1])
    ans%=mod

print(ans)
