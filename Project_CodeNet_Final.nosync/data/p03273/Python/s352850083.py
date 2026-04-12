def main():
    H, W = (int(i) for i in input().split())
    A = [input() for i in range(H)]
    ban_h = set()
    for h in range(H):
        if all(s == "." for s in A[h]):
            ban_h.add(h)
    ban_w = set()
    for w in range(W):
        if all("." == A[i][w] for i in range(H)):
            ban_w.add(w)

    for h in range(H):
        if h in ban_h:
            continue
        for w in range(W):
            if w in ban_w:
                continue
            print(A[h][w], end="")
        print()


if __name__ == '__main__':
    main()
