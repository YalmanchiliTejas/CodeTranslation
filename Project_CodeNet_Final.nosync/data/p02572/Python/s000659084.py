N = int(input())
A = list(map(int, input().split()))
wa = 0
a = 0
for l in range(N-1):
    a += A[N-l-1]
    wa += a * A[N-l-2]
print(wa % (10**9+7))