n = input()
hs = map(int, input().split())

min_hight = 0
cnt = 0

for h in hs:
    if h >= min_hight:
        cnt += 1
        min_hight = h

print(cnt)