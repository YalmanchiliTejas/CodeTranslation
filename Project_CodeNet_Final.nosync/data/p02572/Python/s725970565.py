N = int(input())
A = [int(i) for i in input().split()]
B = []
s = 0
ans = 0
val = 1000000007

for i in range(N):
    s += A[i]
    B.append(s)

for i in range(N-1):
    ans += A[N-i-1] * B[N-i-2]

print(ans % val)