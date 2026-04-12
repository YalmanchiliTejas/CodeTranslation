n = int(raw_input())
H = map(int, raw_input().split())
ans = 0
ph = -1
for h in H:
    if h >= ph:
        ans += 1
        ph = h
print ans