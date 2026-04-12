import sys
from collections import deque
input = sys.stdin.readline

def main():
    H, W = map(int, input().split())
    a = [input().strip() for i in range(H)]
    check = [[False] * W for i in range(H)]
    
    x, y = 0, 0
    check[y][x] = True
    while True:
        fin = True
        for nx, ny in [(x+1, y), (x, y+1)]:
            if 0 <= nx and nx < W and 0 <= ny and ny < H:
                if a[ny][nx] == "#":
                    check[ny][nx] = True
                    fin = False
                    x, y = nx, ny
                    break
        if fin:
            break
    
    ok = False
    if x == W-1 and y == H-1:
        ok = True
        for i in range(H):
            for j in range(W):
                if a[i][j] == "#" and not check[i][j]:
                    ok = False
                    break
            if not ok:
                break

    if ok:
        print("Possible")
    else:
        print("Impossible")



if __name__ == "__main__":
    main()