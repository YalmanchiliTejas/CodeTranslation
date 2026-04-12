N = int(input())
Hs = list(map(int, input().split()))

ans = 0
for i in range(N):
    flag = True
    for j in range(i):
        if Hs[j] > Hs[i]:
            flag = False
    if flag:
        ans += 1

print(ans)