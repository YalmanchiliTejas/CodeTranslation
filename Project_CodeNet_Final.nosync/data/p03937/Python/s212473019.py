import sys
h,w = map(int,input().split())
ls = [list(input()) for _ in range(h)]
i = 0
j = 0
while True:
    flag = False
    if i > 0:
        if ls[i-1][j] == "#":
            print("Impossible")
            sys.exit()
    if i < h-1:
        if ls[i+1][j] == "#":
            if flag == False:
                flag = True
                ls[i][j] = "."
                nx = [0,1,0,0]
            else:
                print("Impossible")
                sys.exit()
    if j > 0:
        if ls[i][j-1] == "#":
            print("Impossible")
            sys.exit()
    if j < w-1:
        if ls[i][j+1] == "#":
            if flag == False:
                flag = True
                ls[i][j] = "."
                nx = [0,0,0,1]
            else:
                print("Impossible")
                sys.exit()
    if i == h-1 and j == w-1:
        break
    if nx[1] == 1:
        i += 1
    else:
        j += 1
print("Possible")
    