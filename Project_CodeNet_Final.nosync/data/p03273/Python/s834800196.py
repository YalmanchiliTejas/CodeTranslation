

def main():
    high, width = map(int, input().split())
    data = [list(input()) for i in range(high)]

    for i in range(high)[::-1]:
        if data[i].count('#') == 0:
            data.pop(i)

    for i in range(width)[::-1]:
        flg = 1
        for j in range(len(data)):
            if data[j][i] == '#':
                flg = 0
                break
        if flg:
            for j in range(len(data)):
                data[j].pop(i)

    for i in range(len(data)):
        print(''.join(data[i]))

if __name__ == '__main__':
    main()
