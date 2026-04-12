h, w = map(int, input().split())
a = [list(input()) for _ in range(h)]

b = [[0]*w for _ in range(h)]

def dfs(i=0, j=0):
    if not (0 <= i < h and 0 <= j < w):
        return
    elif a[i][j] == ".":
        return
    elif b[i][j]:
        return
    else:
        b[i][j] = 1
        dfs(i+1, j)
        dfs(i, j+1)
        for i in range(h):
            for j in range(w):
                if a[i][j] == "#" and b[i][j] == 0:
                    print("Impossible")
                    exit()
        print("Possible")
        exit()

dfs()