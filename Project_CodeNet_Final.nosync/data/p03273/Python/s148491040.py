def main():
    h,w = map(int, input().split())

    A = []
    grid = []
    for i in range(h):
        A.append(input())
    gird = []

    for i in range(h):
        if A[i] != '.'*w:
            grid.append(A[i])

    A = grid.copy()
    w_tmp = len(A[0])
    h_tmp = len(A)
    grid = ['' for _ in range(h_tmp)]
    for i in range(w_tmp):
        tmp = 0
        for j in range(h_tmp):
            if A[j][i] == '.':
                tmp += 1
        if tmp != h_tmp:
            for j in range(h_tmp):
                grid[j] += A[j][i]
    for i in range(len(grid)):
        print(grid[i])


if __name__ == '__main__':
    main()
