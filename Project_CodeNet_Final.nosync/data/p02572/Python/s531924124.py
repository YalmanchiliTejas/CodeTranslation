N = int(input())
A = list(map(int,input().split()))
A_sum = sum(A[1:])

tot = 0
for i in range(N-1):
    tot += (A[i]*A_sum)%(10**9+7)
    tot = tot%(10**9+7)
    A_sum -= A[i+1]
    
print(tot)