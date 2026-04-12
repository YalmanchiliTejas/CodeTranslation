n = int(input())
h = list(map(int, input().split()))
mh = 0
cnt = 0
for i in h:
    if i >= mh:
        cnt += 1
    mh = max(mh, i)
print(cnt)
