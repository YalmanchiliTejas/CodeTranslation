import sys
input = sys.stdin.buffer.readline
MOD = 10**9 + 7

N = int(input())
A = [0] + list(map(int, input().split()))

C = [0]
for i in range(1, len(A)):
    C.append(C[-1] + A[i])

ans = 0
for i in range(1, N):
    ans += A[i] * (C[-1] - C[i])

ans %= MOD
print(ans)
