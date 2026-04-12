N = int(input())
H = list(map(int, input().split()))
ans = 0
for i in range(N):
    flag = 0
    for j in range(i):
        if (H[j] <= H[i]):
            flag += 1
    if (flag == i):
        ans += 1
print(ans)
