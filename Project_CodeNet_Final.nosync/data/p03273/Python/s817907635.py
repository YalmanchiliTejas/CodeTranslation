import copy
H, W = map(int, input().split())

a = [list(input()) for _ in range(H)]
a_copy = a.copy()
for cs in a_copy:
    for c in cs:
        if c == '#':
            break
    else:
        a.remove(cs)

a_copy = copy.deepcopy(a)
count = 0
for row in range(len(a_copy[0])):
    for line in range(len(a_copy)):
        if a_copy[line][row] == '#':
            break
    else:
        for line in range(len(a_copy)):
            del a[line][row - count]
        count += 1

for cs in a:
    for c in cs:
        print(c, end='')
    print()