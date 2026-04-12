n = int(input())
h = list(map(int, input().split()))
highest = 0
ans = 0
for i in h:
    if (i >= highest):
        highest = i
        ans += 1
print(ans)