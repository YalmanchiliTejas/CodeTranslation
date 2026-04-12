h, w = map(int, input().split())
board = [str(input()) for i in range(h)]

for i in range(h-1):
    for j in range(w-1):
        if board[i][j+1] == "#" and board[i+1][j] == "#":
            print("Impossible")
            exit()
        
print("Possible")