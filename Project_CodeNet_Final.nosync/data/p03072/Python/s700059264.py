n = int(input())
H = [int(a) for a in input().split()]

cnt = 0
ma = 0
for h in H:
    if ma <= h:
        cnt += 1
        ma = h

print(cnt)