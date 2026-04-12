N=int(input())
A=list(map(int,input().split()))
wa=[0]*(N-1)
wa[0]=A[-1]
for i in range(1,N-1):
    wa[i]=wa[i-1]+A[N-i-1]
ans=0
wa.reverse()

for i in range(0,N-1):

    ans=(ans+wa[i]*A[i])%(10**9+7)
print(ans)
