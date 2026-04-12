N = int(input())
L = list(map(int, input().split()))
for i in range(N):
    if i == 0:
        cnt = 1
        maxN = L[i]
    else:
        if L[i] - maxN >= 0:
            cnt += 1
            maxN = L[i]
print(cnt)

