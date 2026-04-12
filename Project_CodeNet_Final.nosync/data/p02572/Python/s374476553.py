INF=10**9+7
n=int(input())
A=list(map(int,input().split()))
S=[sum(A)]
ans=0
for i in range(len(A)):
    key=S[-1]
    S.append(key-A[i])
    ans+=(A[i]*S[-1])
    
print(ans%INF)