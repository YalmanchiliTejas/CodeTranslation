n = int(input())
a = list(map(int, input().split()))

maxv = 0
result = 0
for v in a:
    if maxv <= v:
        result += 1
        maxv = v
print(result)
