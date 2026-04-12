n = int(input())
hl = [int(x) for x in input().split()]

t = [0]
r = 0
for a in hl:
    if max(t) <= a:
        r += 1
    t.append(a)

print(r)
