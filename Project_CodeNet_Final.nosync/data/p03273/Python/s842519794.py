h, w = map(int, input().split())
a = list(input() for i in range(h))

a = list(zip(*[i for i in a if "#" in i]))
a = list(zip(*[i for i in a if "#" in i]))

for i in a:
    print("".join(i))