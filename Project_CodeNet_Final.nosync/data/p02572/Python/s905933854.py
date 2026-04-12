N = int(input())
A = input().split()
B = [0]*N

for i in range(N):
  A[i] = int(A[i])
  B[i] = A[i]*A[i]

print( ( ( (sum(A)*sum(A)) - sum(B) ) // 2 ) % ( 10**9 + 7 ) )
