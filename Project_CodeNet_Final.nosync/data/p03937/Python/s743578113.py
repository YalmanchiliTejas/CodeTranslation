
def dfs(x, y): 
    if x == h-1 and y == w-1:
        a[x][y] = "."
        # print(a)
        for i in range(h):
            if "#" in a[i]:
                print("Impossible")
                exit()
        print("Possible")
        exit()
    
    if a[x][y] == "#":
        a[x][y] = "."

    if y+1 < w and a[x][y+1] != ".":
        dfs(x, y+1)#右
    
    if x+1 < h and a[x+1][y] != ".":
        dfs(x+1, y)#下
    
    for i in range(h):
        if "#" in a[i]:
            print("Impossible")
            exit()
    print("Possible")
    exit()

h, w = map(int, input().split())
a = []
for i in range(h):
    a.append(list(input()))

dfs(0, 0)