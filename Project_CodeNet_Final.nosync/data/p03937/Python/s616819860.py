def main():
    H, W = map(int, input().split())
    A = []
    for _ in range(H):
        A.append(input())

    count = 0
    for i in range(H):
        for j in range(W):
            if A[i][j] == "#":
                count += 1
    if count == H+W-1:
        return "Possible"
    return "Impossible"

if __name__ == '__main__':
    print(main())