def main():
    H, W = map(int, input().split())
    A = [0]*H
    for i in range(H):
       A[i] = [a for a in input()]
    # print(A)
    B = []
    for i in range(H):
        found = False
        for j in range(W):
            if A[i][j] == '#':
                found = True
                break
        if found:
            B.append(A[i])
    # print(B)
    h = len(B)
    C = [[] for i in range(h)]
    for j in range(W):
        found = False
        for i in range(h):
            if B[i][j] == '#':
                found = True
                break
        if found:
            for i in range(h):
                C[i].append(B[i][j])
    for i in range(h):
        print(''.join(C[i]))


if __name__ == '__main__':
    main()
