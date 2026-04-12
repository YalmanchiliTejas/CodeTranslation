N = int(input())
A = list(map(int, input().split()))
D = 1000000007


ans = 0
B = [0] * (N + 1)

for i in range(N-1, -1, -1):
    B[i] = (B[i+1] + A[i]) % D

for i in range(0, N-1):
    ans += (A[i] * B[i+1]) % D

print(int(ans % D))