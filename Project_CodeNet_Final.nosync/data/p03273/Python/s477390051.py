H, W = list(map(int, input().strip().split(" ")))

field = []
hist = [0 for w in range(W)]

def shrink():
    newField = []
    for h in range(H):
        line = []
        for w in range(W):
            if(hist[w] != H):
                line.append(field[h][w])
        newField.append(line)        
    return newField            

for h in range(H):
    line = list(input().strip())
    if(line.count(".") != len(line)):
        field.append(list(line))
        for w in range(W):
            hist[w] += 1 if field[-1][w] == "." else 0 
H = len(field)

newField = shrink()

for h in newField:
    print("".join(h))