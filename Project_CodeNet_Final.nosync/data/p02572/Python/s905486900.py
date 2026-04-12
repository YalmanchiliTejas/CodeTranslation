N = int(input())
A = list(map(int, input().split()))
B = sum(A)
cnt = 0
for i in range(N-1):
    B -= A[i]
    cnt += A[i]*B

print(cnt%((10**9)+7))