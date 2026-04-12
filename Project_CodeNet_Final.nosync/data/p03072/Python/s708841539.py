N = int(input())
hm = 0
cnt = 0
for h in map(int,input().split()):
    if h >= hm:
        cnt += 1
        hm = h

print(cnt)