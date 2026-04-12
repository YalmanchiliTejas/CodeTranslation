h,w=map(int, input().split())

grid=[]
result=[]

for i in range(h):
    buf=input()
    if len(buf) == buf.count("."):
        continue
    else:
        grid.append(buf)

for x in zip(*grid):
    if len(x) == x.count("."):
        continue
    else:
        result.append(x)

for x in zip(*result):
    print("".join(x))