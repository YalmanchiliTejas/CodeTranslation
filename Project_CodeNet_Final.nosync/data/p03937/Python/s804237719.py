H,W = map(int, input().split())

edge = [["." for _ in range(W+2)]]
center = [["."] + list(input()) + ["."] for i in range(H)]
A_array = edge + center + edge

def is_there_OK_move(before_i,before_j,before_move):
    if before_move == "right":
        i = before_i
        j = before_j + 1
    elif before_move == "down":
        i = before_i + 1
        j = before_j

    up = A_array[i-1][j]
    down = A_array[i+1][j]
    right = A_array[i][j+1]
    left = A_array[i][j-1]
    
    if i == H and j == W:
        if up == left == "#":
            return -1
        else:
            return 1
    elif (down == right == "#") or (before_move == "right" and up == "#") or (before_move == "down" and left == "#"):
        return -1
    else:
        if down == "#":
            return is_there_OK_move(i,j,"down")
        elif right == "#":
            return is_there_OK_move(i,j,"right")


ans = is_there_OK_move(0,1,"down")

if ans == 1:
    print("Possible")
else:
    print("Impossible")