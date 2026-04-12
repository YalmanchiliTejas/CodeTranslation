n = int(input())
H = list(map(int, input().split()))
cnt = 0
highest = 0
for h in H:
    if h >= highest:
        cnt += 1
        highest = h
print(cnt)
