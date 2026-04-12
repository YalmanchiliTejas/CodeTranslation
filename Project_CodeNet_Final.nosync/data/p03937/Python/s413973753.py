def solve():
    h, w = map(int, input().split())
    a = [list(input()) for _ in range(h)]
    for i in range(h-1):
        for j in range(w-1):
            if a[i][j:j+2] == ["#","#"]:
                if a[i+1][j] == '#':
                    print("Impossible")
                    exit()
        for k in range(1,w):
            if a[i][k] == "#":
                if a[i+1][k-2:k] == ["#","#"]:
                    print("Impossible")
                    exit()
    if a[h-2][-1] == "#":
        if a[h-1][-2] == "#":
            print("Impossible")
            exit()
    print("Possible")
    return 0

if __name__ == "__main__":
    solve()
