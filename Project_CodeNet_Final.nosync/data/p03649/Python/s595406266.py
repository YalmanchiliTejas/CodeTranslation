N = int(input())
A = [int(a) for a in input().split()]

ans = 0
A.sort(reverse=True)
while A[0] >= N:
    num = A[0] // N
    ans += num
    A[0] %= N
    for i in range(1, N):
        A[i] += num
    A.sort(reverse=True)

print(ans)