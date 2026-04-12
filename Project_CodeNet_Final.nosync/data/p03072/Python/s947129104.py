n = int(input())
l = [int(i) for i in input().split()]
r = m = 0
for a in l:
    if m <= a:
        r += 1
        m = a
print(r)
