n = int(input())
H = list(map(int,input().rstrip().split()))
M = 0
ans = 0
for i in range(len(H)):
    if H[i] >= M:
        ans += 1
        M = H[i]
print(ans)