N = int(input())

H_all = list(map(int,input().split()))
Mount = []
ans = 0
for i in range(N):
    H = H_all[i]
    Mount.append(H)
    if max(Mount) <= H:
        ans += 1
print(ans)