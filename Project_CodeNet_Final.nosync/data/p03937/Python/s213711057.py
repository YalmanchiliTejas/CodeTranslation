if __name__ == "__main__":
    h, w = map(int, input().split())
    a = list()
    for i in range(h):
        a.append(input())

    count = 0
    for i in range(h):
        for j in range(w):
            if a[i][j] == '#':
                count += 1

    if count == h + w - 1:
        print('Possible')
    else:
        print('Impossible')
