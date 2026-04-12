import itertools
from sys import stdin
H,W = [int(x) for x in stdin.readline().rstrip().split()]
data = []
for _ in range(H):
    data.append(list(input()))

right = 0
down  = 0
for i in data:
    for j in range(0,W-1):
        if i[j] == "#" and i[j+1] == "#":
            right += 1

data_t = []
for i in range(W):
    row = []
    for vector in data:
        row.append(vector[i])
    data_t.append(row)

for i in data_t:
    for j in range(0,H-1):
        if i[j] == "#" and i[j+1] == "#":
            down += 1

if down == H-1 and right == W-1:
    print("Possible")
else:
    print("Impossible")