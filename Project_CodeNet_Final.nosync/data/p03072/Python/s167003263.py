n = int(input())
h = list(map(int, input().split()))
mx = 0
cnt = 0
for i in h:
    mx = max(mx, i)
    if i==mx:
        cnt += 1
print(cnt)