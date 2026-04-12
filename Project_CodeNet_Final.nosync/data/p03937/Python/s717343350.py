from itertools import chain

H, W = map(int, input().split())
count = 0
for _ in range(H):
    l = list(input())
    count += l.count("#")

if count == H+W - 1:
    print("Possible")
else:
    print("Impossible")