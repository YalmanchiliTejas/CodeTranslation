N=int(input())
A=list(map(int,input().split()))
sumA=0
sumB=[0]
for i in range(N):
    sumB.append(sumB[i]+A[i])
    i=i+1
for j in range(N-1):
    sumA=sumA+(A[j]*(sumB[N]-sumB[j+1]))%(10**9+7)
    j=j+1
print(sumA%(10**9+7))