h, w = map(int, input().split())
array = [input() for x in range(h)]
res_array = []
for row in array:
    if len(row) != row.count("."):
        res_array.append(row)

array2 = [x for x in zip(*res_array)]
res_array2 = []
for row in array2:
    if len(row) != row.count("."):
        res_array2.append(row)

for i in [x for x in zip(*res_array2)]:
    print("".join(i))