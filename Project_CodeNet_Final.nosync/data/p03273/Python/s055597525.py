h, w = map(int, input().split(' '))
a = [list(str(input())) for _ in range(h)]
checker = []
for i in range(len(a)):
    if all(x == '.' for x in a[i]):
        checker.append(i)
    else:
        continue
for i in range(1, len(checker)+1):
    a.pop(checker[-i])
checker = []
for i in range(len(a[0])):
    if all(a[j][i] == '.' for j in range(len(a))):
        checker.append(i)
    else:
        continue
for i in range(1, len(checker)+1):
    for j in range(len(a)):
        a[j].pop(checker[-i])


for i in a:
    print(''.join(i))