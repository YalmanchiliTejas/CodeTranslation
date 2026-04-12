n = int(input())
h = list(map(int, input().split()))
cnt = 0
highest = 0
for i in h:
    if i >= highest:
        highest = i
        cnt += 1
print(cnt)