def getN():
    return int(input())

def getMN():
    a = input().split()
    b = [int(i) for i in a]
    return b[0],b[1]

def getlist():
    a = input().split()
    b = [int(i) for i in a]
    return b

H, W =getMN()
all = []
for i in range(H):
    a = input()
    if "#" in a:
        all.append(a)

length = len(all[0])
raw = [0 for i in range(length)]

for r in all:
    for i in range(length):
        if r[i] == "#":
            raw[i] = 1

for r in all:
    for i in range(length):
        if raw[i] == 1:
            print(r[i],end="")
    print("")


