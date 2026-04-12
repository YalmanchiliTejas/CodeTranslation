n=int(input())
A=[int(_) for _ in input().split()]
full=0
sumsum=0
for a in range(len(A)-1):
    sumsum=(sumsum+A[len(A)-a-1])%(10**9+7)
    full=(full+sumsum*A[len(A)-a-2])%(10**9+7)

print(full)

