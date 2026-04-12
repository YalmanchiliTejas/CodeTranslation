l = int(input())
heights = list(map(int, input().split()))

v = [True] * l

for i in range(l):
    for j in range(i + 1, l):
        if v[j]:
            v[j] = (heights[i] <= heights[j])

print(sum(v))
