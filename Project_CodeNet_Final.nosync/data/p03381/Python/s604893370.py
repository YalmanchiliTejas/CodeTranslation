N=int(input())

X=list(map(int,input().split()))

A=X.copy()
A.sort(reverse=True)

left=A[int(N/2)-1]
right=A[int(N/2)]

for i in range(N):
  if X[i]>=left:
    print(right)
  else:
    print(left)