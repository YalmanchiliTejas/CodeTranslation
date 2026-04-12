N = int(input())
hs = list(map(int, input().split()))
ans = N
for i in range(1, N):
    for j in range(i):
        if hs[i] < hs[j]:
            ans -= 1
            break
print(ans)