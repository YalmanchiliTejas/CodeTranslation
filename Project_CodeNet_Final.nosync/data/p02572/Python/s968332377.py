N = int(input())
A = list(map(int, input().split()))
M = 10**9+7

ruisekiwa = [0]*N
wa = sum(A)%M

result = 0
for i in range(N):
    wa -= A[i]
    result = (result+(A[i]*wa)%M)%M

print(result)