N = int(input())
H = map(int, input().split())

hi = next(H)
cnt = 1
for h in H:
    if h >= hi:
        cnt += 1
        hi = h

print(cnt)
