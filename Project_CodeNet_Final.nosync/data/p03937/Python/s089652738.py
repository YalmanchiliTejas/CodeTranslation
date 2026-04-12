def main():
    h, w = map(int, input().split())

    a = []
    for i in range(h):
        a.append(input())

    count = 0

    for i in range(h):
        for j in range(w):
            if a[i][j] == '#':
                count += 1

    if count == h + w - 1:
        print("Possible")
    else:
        print("Impossible")


'''
    for i in range(h):
        a.append(input()+'.')

    a.append('.' * (w-1))

    print(a)
    i = 0
    j = 0
    while True:
        if last == 'up':
            if a[i+1][j] == '#' and a[i][j+1] == '.':
                last = 'up'
                i += 1
            elif a[i+1][j] == '.' and a[i][j+1] == '#':
                last = 'left'
                j += 1
            else:
                print('Impossible')
                return 0
        if i == h-1 and j == w-1:
            break
        print(i, j)

    print('Possible')
    return 0
'''

if __name__ == "__main__":
    main()


'''

possible判定条件

前のコマの位置（左or上）以外は右or下のみに#がある
コマの移動はすべて連続である
コマの移動数はH+W-1である

'''
