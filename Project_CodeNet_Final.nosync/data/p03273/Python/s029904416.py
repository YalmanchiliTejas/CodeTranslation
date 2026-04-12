arr = []

h, w = [int(i) for i in input().split()]
for _ in range(h):
    arr.append(input())

result = []
for ar in arr:
    if not '#' in ar:
        continue
    result.append(ar)

h = len(result)
w = len(result[0])


# print(result)
# print(h, w)

result2 = []
for j in range(w):
    flag = True
    for i in range(h):
        if result[i][j] == '#':
            flag = False
    if flag:
        result2.append(j)

if result2:

    result3 = []
    for s in result:
        line = ''
        for i, c in enumerate(s):
            if i in result2:
                continue
            line += c
        result3.append(line)
else:
    result3 = result


# print()
# print(result)
# print(result2)
for line in result3:
    print(line)