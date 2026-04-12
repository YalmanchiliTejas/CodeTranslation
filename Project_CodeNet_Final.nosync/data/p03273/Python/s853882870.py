h, w = map(int, input().split())
a = []
for i in range(h):
    wi = input()
    if wi != "."*w:
        a.append(wi)
b = zip(*[x for x in zip(*a) if "#" in x])
for i in b:
    print("".join(i))