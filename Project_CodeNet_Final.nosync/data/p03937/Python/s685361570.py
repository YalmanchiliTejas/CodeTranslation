h, w = [int(item) for item in input().split()]
field = [input().rstrip() for _ in range(h)]
path = 0
for line in field:
    path += line.count("#")
if path != h + w - 1:
    print("Impossible")
else:
    print("Possible")