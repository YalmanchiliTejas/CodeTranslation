N = int(input())
A = list(map(int,input().split()))

#累積和を計算
SumA = [0]*(N+1)
n = 1
for i in range(N):
	SumA[i+1] = SumA[i] + A[i]

#A*Aの全パターンを計算
AA = []
for j in range(N):
	AA.append(A[j]*(SumA[N]-SumA[j+1]))

#合計を計算
ans = sum(AA)%1000000007
print(ans)