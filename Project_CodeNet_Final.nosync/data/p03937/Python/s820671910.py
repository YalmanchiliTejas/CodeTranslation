h, w = map(int, input().split())

a = []
count = 0

for i in range(h):
    a.append(list(input()))
    count += a[i].count("#")

if count == h + w - 1:
    print("Possible")
else:
    print("Impossible")
