N = int(input())
H = list(map(int, input().strip().split(' ')))

height = 0
res = 0
for h in H:
    if h >= height:
        res += 1
    height = max(height, h)

print(res)
