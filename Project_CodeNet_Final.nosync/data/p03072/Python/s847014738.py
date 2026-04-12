n = int(input())
l = list(map(int, input().split()))
highest = l[0]
ans = 1
for i in range(1, n):
    if l[i] >= highest:
        ans += 1
        highest = l[i]
print(ans)