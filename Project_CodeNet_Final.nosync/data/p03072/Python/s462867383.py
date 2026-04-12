N = int(input())
li = list(map(int, input().split()))
ans = 1
max_height = li[0]
for i in range(1, N):
    if li[i] >= max_height:
        ans += 1
        max_height = li[i]
print(ans)