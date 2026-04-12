def main():
    H, W = map(int, input().split())
    a = []
    for _ in range(H):
        a.append(input())
    h = []
    w = []
    for i in range(H):
        if a[i] == "."*W:
            h.append(i)
    for i in range(W):
        b = ""
        for j in range(H):
            b += a[j][i]
        if b == "."*H:
            w.append(i)
    
    for i in range(H):
        out = ""
        for j in range(W):
            if (i in h) or (j in w):
                out += ""
            else:
                out += a[i][j]
        if out != "":
            print(out)

if __name__ == "__main__":
    main()
