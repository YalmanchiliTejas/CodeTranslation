n = int(input())
h = list(map(int, input().split()))

ans = 1
height = h[0]
for i in range(n-1):
    if height <= h[i+1]:
        ans += 1
        height = h[i+1] # 高さを更新
    # print(ans,height)

print(ans)
