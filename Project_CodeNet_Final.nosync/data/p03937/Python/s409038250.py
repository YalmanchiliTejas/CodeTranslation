H, W = map(int,input().split())
pos = 0
for _ in range(H):
    line = input()
    for i, l in enumerate(line):
        if l == "#":
            if i < pos:
                print("Impossible")
                exit()
            if pos < i:
                pos = i
print("Possible")
