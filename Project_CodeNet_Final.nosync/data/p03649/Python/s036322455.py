N = int(input())
a = list(map(int, input().split()))

ans = 0
while max(a) >= N:
    for i in range(N):
        if a[i] >= N:
            tmp = a[i] // N
            for j in range(N):
                if j == i:
                    a[j] -= tmp*N
                else:
                    a[j] += tmp
            ans += tmp

print(ans)