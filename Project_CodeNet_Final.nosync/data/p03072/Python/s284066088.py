n = int(input())
h = map(int, input().split())

high = 0
c = 0
for h_ in h:
    if high <= h_:
        c += 1
        high = h_
print(c)