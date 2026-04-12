a,b=list(map(int, input().split()))
n = [list(str(input())) for _ in range(a)]

y = []
for i, name in enumerate(n):
    if not all([j == "." for j in name]):
        y.append(name)

nc = []
for _ in range(len(y[0])):
    nnc = []
    for _ in range(len(y)):
        nnc.append("#")
    nc.append(nnc)

for i, name in enumerate(y):
    for k, name2 in enumerate(name):
        nc[k][i] = name2

z = []
for i, name in enumerate(nc):
    if not all([j == "." for j in name]):
        z.append(name)

nc = []
for _ in range(len(z[0])):
    nnc = []
    for _ in range(len(z)):
        nnc.append("#")
    nc.append(nnc)

for i, name in enumerate(z):
    for k, name2 in enumerate(name):
        nc[k][i] = name2

for i in nc:
    print("".join(i))