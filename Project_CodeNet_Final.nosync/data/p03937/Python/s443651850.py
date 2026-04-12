h, w = map(int, input().split())
count = 0
for i in range(h):
    count += input().count("#")
if w + h - 1 == count:
    print("Possible")
else:
    print("Impossible")