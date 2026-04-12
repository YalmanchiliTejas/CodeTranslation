N = int(input())
hotel = list(map(int, input().split(" ")))
ans = 0
hight = hotel[0]

for j in range(N):
    if hight <= hotel[j]:
        ans += 1
        hight = hotel[j]

print(ans)
