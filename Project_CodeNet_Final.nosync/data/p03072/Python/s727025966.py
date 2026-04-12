n = int(input())
h = [int(x) for x in input().split()]
limit = h.pop(0)
result = 1
for height in h:
    if height >= limit:
        result += 1
        limit = height
print(result)