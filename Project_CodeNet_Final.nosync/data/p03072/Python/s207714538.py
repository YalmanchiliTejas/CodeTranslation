N = int(input())
H = [int(x) for x in input().split()]

m = 0
ret = 0
for h in H:
    if m <= h:
        ret += 1
    m = max(m, h)

print(ret)
