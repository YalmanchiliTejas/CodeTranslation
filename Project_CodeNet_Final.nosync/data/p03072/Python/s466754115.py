n = int(input())
h_seq = list(map(int, input().split()))

ans = 0
r = 0
for h in h_seq:
    if h >= r:
        ans += 1
        r = h

print(ans)
