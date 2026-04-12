N = int(input())
H = list(map(int, input().split()))

ok = 0
h_max = 0
for h_self in H:
    if h_max <= h_self:
        ok += 1
        h_max = h_self

print(ok)
