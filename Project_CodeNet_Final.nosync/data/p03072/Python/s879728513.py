n = int(input())
H = list(map(int, input().split()))

highest = 0
cnt = 0

for i in H:
    if i >= highest:
        highest = i
        cnt += 1
print(cnt)