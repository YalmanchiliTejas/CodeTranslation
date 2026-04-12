n = int(input())
max_height = 0
res = 0
for elem in input().split():
    h = int(elem)
    if max_height <= h:
        res += 1
        max_height = h
print(res)