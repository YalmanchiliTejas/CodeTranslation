n = int(input())
H = list(map(int,input().split()))
a = H[0]
cnt = 0
for h in H:
    if a <= h:
        a = h
        cnt += 1
print(cnt)