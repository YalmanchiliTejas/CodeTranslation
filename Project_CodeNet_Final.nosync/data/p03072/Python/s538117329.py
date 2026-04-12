N = int(input())
hs = list(map(int, input().split()))

m = 0
count = 0

for h in hs:
    if m <= h:
        count += 1
        m = h

print(count)