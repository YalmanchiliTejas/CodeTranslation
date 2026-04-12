N=int(input())
A=list(map(int,input().split()))
B=[]
for i in range(N):
    B.append(A[i]**2)
ans=(sum(A)**2-sum(B))//2
print(ans%(10**9+7))