h, w = map(int, input().split())
a = [list(input()) for _ in range(h)]

l = []
for i, v in enumerate(a):
    if "#" not in v:
        l.append(i)
for i in l[::-1]:
    a.pop(i)

a = list(zip(*a))
l = []
for i, v in enumerate(a):
    if "#" not in v:
        l.append(i)
for i in l[::-1]:
    a.pop(i)

a = list(zip(*a))
for i in a:
    print("".join(i))