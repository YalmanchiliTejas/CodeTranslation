import sys
read = sys.stdin.read
readlines = sys.stdin.readlines
def main():
    h, w = map(int, input().split())
    a = []
    row_ng = ['.'] * w
    for _ in range(h):
        row = list(input())
        if row == row_ng:
            h -= 1
        else:
            a.append(row)

    a2 = [[] for _ in range(h)]
    for i1 in range(w):
        flag = False
        for i2 in range(h):
            if a[i2][i1] == '#':
                flag = True
                break
        if flag:
            for i3 in range(h):
                a2[i3].append(a[i3][i1])

    for arow in a2:
        print("".join(arow))

if __name__ == '__main__':
    main()