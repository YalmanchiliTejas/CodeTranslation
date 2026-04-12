def main():
    H, W = map(int, input().split())
    A = []
    for _ in range(H):
        A.append([a for a in input()])
    removeR = []
    for i in range(H):
        if all(A[i][j] == "." for j in range(W)):
            removeR.append(i)
    removeC = []
    for j in range(W):
        if all(A[i][j] == "." for i in range(H)):
            removeC.append(j)
    B = []
    for i in range(H):
        if i not in removeR:
            temp = []
            for j in range(W):
                if j not in removeC:
                    temp.append(A[i][j])
            B.append(temp)

    return B

if __name__ == '__main__':
    B = main()
    for i in range(len(B)):
        print("".join(B[i]))