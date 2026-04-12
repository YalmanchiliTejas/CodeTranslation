n, x = map(int, input().split())

heights = [1]
putties = [1]
for _ in range(50):
    heights.append(heights[-1] * 2 + 3)
    putties.append(putties[-1] * 2 + 1)

def burger(l, y):
    if l == 0:
        return y
    if y <= l:
        return 0
    hl = heights[l]
    if y >= hl - l:
        return putties[l]

    if hl // 2 + 1 <= y:
        return putties[l - 1] + 1 + burger(l - 1, y - (hl // 2 + 1))

    return burger(l - 1, y - 1)


print(burger(n, x))
