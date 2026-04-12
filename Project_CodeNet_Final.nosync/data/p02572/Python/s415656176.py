N = int(input())
A = list(map(int, input().split()))
sum = sum(A)
cnt = 0
for i in range(N-1):
    sum -= A[i]
    cnt += A[i]*sum
print(cnt%((10**9)+7))