H, W= map(int, raw_input().split())
array = []
for i in range(H):
    array.append(list(raw_input()))


left = 0
possible = True
for i in range(H):
    for j in range(W):
        if array[i][j] == "#":
            if j < left:
                possible = False
                break
            if j > left:
                left = j

if possible:
    print "Possible"
else:
    print "Impossible"
    
