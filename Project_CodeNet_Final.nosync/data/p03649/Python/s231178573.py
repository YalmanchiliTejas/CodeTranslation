N = int(input())
A = list(map(int, input().split()))
ans = 0
flag = True
while flag:
    flag = False
    for i in range(N):
        if A[i] >= N:
            count = A[i] // N
            ans += count
            for j in range(N):
                A[j] += count
            A[i] -= count
            A[i] %= N
            flag = True

print(ans)
