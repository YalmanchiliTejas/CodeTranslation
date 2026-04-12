N = int(input())
H = map(int, input().split())
highest = 0
ans = 0
for height in H:
    if height >= highest:
        ans += 1
        highest = height
print(ans)
