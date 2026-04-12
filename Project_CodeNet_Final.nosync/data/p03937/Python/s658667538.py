H,W = map(int,input().split())
h = 0
w = 0
flag = 0
ans = 0
counter = 0
L = []
for i in range(H) :
    l = input()
    counter += l.count("#")
    L.append(l)

while flag == 0 :
    if h == (H-1) and w == (W-1) :
        ans = 1
        flag = 1
    else :
        if w == (W-1) :
            if L[h+1][w] == "#" :
                h += 1
            else :
                flag = 1
        elif h == (H-1) :
            if L[h][w+1] == "#" :
                w += 1
            else :
                flag = 1
        else :
            if L[h+1][w] == "#" and L[h][w+1] == "#" :
                flag = 1
            else :
                if L[h+1][w] == "#" :
                    h += 1
                elif L[h][w+1] == "#" :
                    w += 1
                else :
                    flag = 1
                
if ans == 1 and ((H+W-1) == counter) :
    print("Possible")
else :
    print("Impossible")
