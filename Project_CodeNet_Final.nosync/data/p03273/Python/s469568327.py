a, b = map(int, input().split(" "))

c = [list(input()) for i in range(a)]

d = [False, 0]

for i in range(a):
    if d[0]:
        i -= d[1]
    if c[i] == ['.' for i in range(b)]:
        del c[i]
        d[0] = True
        d[1] += 1
a -= d[1]
c = list(map(list, zip(*c)))
d = [False, 0]

for i in range(b):
    if d[0]:
        i -= d[1]
    if c[i] == ['.' for i in range(a)]:
        del c[i]
        d[0] = True
        d[1] += 1
b -= d[1]

if len(c) == 1:
    print("#")
else:
    for i in list(map(list, zip(*c))):
        for j in range(b):
            print(i[j], end="")
        print()
