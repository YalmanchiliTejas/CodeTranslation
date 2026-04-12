h,w = map(int,input().split())
x = 0
y = 0
time = 0
cou = 0
lis = ""
for i in range(h):lis += str(input())
for i in range(h * w):
    if lis[i] == "#":
        cou += 1
for i in range(h):
    while lis[i * w + x] == "#" and y == 0:
        x += 1
        time += 1
        if x == w:
            x -= 1
            y = 1
    if i == h-1 and time == (h + w)-1 and time == cou:
        print("Possible")
        exit()
    time += 1
print("Impossible")