n = int(input())
hs = map(int, input().split())

min_h = 0
result = 0

for h in hs:
    if h >= min_h:
        result += 1
        min_h = h
print(result)
