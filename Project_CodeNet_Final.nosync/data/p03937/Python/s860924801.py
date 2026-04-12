def main():
    h, w = list(map(int, input().split()))
    A = [['.'] * (w + 2)] + [['.', ] + list(input()) + ['.', ] for _ in range(h)] + [['.'] * (w + 2)]
    i, j = 1, 1
    while True:
        A[i][j] = '.'
        if i == h and j == w:
            break
        if A[i + 1][j] == A[i][j + 1]:
            print('Impossible')
            exit()
        if A[i + 1][j] == '#':
            i += 1
        else:
            j += 1
    for a in A:
        if any([i == '#' for i in a]):
            print('Impossible')
            break
    else:
        print('Possible')

if __name__ == '__main__':
    main()
