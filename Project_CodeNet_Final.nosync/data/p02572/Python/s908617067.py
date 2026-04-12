#C
p = 10**9+7

N=int(input())
A=list(map(int,input().split()))
B=[A[0]]
for i in range(1,N):
    B.append(B[-1]+A[i])
#print(B)

ans=0
for i in range(N-1):
    tmp= (A[i]*(B[-1]-B[i]))%p
    ans = (ans+tmp)%p
print(ans)