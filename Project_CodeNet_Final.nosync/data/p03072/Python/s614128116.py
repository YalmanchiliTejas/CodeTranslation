n = int(input())
hs = [int(i) for i in input().split(' ')]

s = 1
for i in range(1, n):
    if all(map(lambda x: x <= hs[i], hs[:i])):
        s += 1

print(s)