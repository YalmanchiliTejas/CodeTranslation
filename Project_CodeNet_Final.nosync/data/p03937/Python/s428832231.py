def main():
    H,W = map(int,input().split())
    root = [list(str(input())) for _ in range(H)]
    _long = [[0 for _ in range(W)] for _ in range(H)]
    _long[0][0] = 1
    al = 0
    for i in range(H):
        for j in range(W):
            if root[i][j] == "#":
                al += 1
    
    if al != H+W-1:
        print("Impossible")
        exit()
    
    print("Possible")
    
if __name__ == "__main__":
    main()
