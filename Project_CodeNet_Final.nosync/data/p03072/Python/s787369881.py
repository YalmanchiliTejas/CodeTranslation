input()
(*H,) = map(int, input().split())

cnt = 0
a = 0
for h in H:
    if a <= h:
        cnt += 1
        a = h
print(cnt)