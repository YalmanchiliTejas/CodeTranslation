int_h, int_w = map(int, input().split())

masu = list()

for i in range(int_h):
    masu.append(list(input()))

conv = list()
for x in list(map(list, zip(*masu))):
    if "#" in x:
        conv.append(x)

result = list()

for y in list(map(list, zip(*conv))):
    if "#" in y:
        result.append(y)

for r in result:
    print("".join(r))
