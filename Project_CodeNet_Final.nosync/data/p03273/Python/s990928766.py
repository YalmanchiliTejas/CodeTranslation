def main():
    H, W = (int(i) for i in input().split())
    A = [input() for i in range(H)]
    cut_h = []
    cut_w = []
    for h in range(H):
        if all(s == "." for s in A[h]):
            cut_h.append(h)
    for w in range(W):
        if all("." == A[i][w] for i in range(H)):
            cut_w.append(w)
    for h in range(H):
        if h in cut_h:
            continue
        for w in range(W):
            if w in cut_w:
                continue
            print(A[h][w], end="")
        print()


if __name__ == '__main__':
    main()
