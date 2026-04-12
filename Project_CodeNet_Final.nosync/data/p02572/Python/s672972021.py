N = int(input())
A = list(map(int, input().split()))


def mod10_9_7(num):
    return num % (10**9+7)


seki = A[-1]

ans = 0
for i in range(N-2, -1, -1):
    ans += A[i] * seki
    seki += A[i]
print(mod10_9_7(ans))
