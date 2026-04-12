import sys
def input(): return sys.stdin.readline().strip()


def main():
    H, W = map(int, input().split())
    A = [list(input()) for _ in range(H)]
    omit = set([])
    for j in range(W):
        white = True
        for i in range(H):
            if A[i][j] == '#':
                white = False
                break
        if white: omit.add(j)
    for i in range(H):
        white = True
        for j in range(W):
            if A[i][j] == "#":
                white = False
                break
        if white: continue
        ans = ""
        for j in range(W):
            if j not in omit:
                ans += A[i][j]
        print(ans)


if __name__ == "__main__":
    main()
