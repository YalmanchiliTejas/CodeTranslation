n = int(input())
hs = list(map(int, input().split()))

max = 0
c = 0

for h in hs:
    if h >= max:
        c += 1
        max = h

print(c)
