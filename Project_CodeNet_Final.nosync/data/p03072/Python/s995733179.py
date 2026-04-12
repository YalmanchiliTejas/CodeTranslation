N = int(input())
H = list(map(int,input().split()))

# highest_height[i]は西から0,1,...,i番目のうち最も高い山の高さ
highest_height = [H[0]]
for i in range(1,N):
    highest_height.append(max(highest_height[-1],H[i]))

ans = 0
for i in range(N):
    if H[i] >= highest_height[i]:
        ans += 1

print(ans)