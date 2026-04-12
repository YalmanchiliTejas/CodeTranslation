from sys import stdin

h,w = [int(x) for x in stdin.readline().rstrip().split()]
li = [stdin.readline().rstrip() for _ in range(h)]

now = 0

for i in range(h):
    if "#" in li[i][:now]:
        print("Impossible")
        exit()
    for j in range(now,w-1):
        if li[i][j] == "#" and li[i][j+1] == ".":
            now = j
        if li[i][w-2] == "#" and li[i][w-1] == "#":
            now = w-1
    if now <= 3:
        if "#" in li[i][now+1:]:
            print("Impossible")
            exit()
print("Possible")