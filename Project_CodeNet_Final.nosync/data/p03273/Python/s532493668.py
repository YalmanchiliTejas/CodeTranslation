H, W = map(int, input().split())

grid = [list(input()) for _ in range(H)]
l = [x for x in grid if "#" in x]
l = [x for x in zip(*l) if "#" in x]

for i in zip(*l):
    print("".join(i))