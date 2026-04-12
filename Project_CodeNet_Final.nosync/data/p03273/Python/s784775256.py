import numpy as np


def yoko(row):
    cnt = sum(row)
    return cnt == len(row)


def main():
    h, w = map(int, input().split(' '))
    a = []

    for i in range(h):
        b = input()
        a += [1 if c == '.' else 0 for c in b]
    a = np.array(a).reshape(h, w)

    while True:
        cnt = 0
        del_list = []
        for i in range(len(a)):
            judge = yoko(a[i])
            if judge:
                del_list.append(i)

        if len(del_list):
            del_cnt = 0
            for idx in del_list:
                a = np.delete(a, idx - del_cnt, axis=0)
                del_cnt += 1
        else:
            cnt += 1

        a = a.T

        del_list = []
        for i in range(len(a)):
            judge = yoko(a[i])
            if judge:
                del_list.append(i)

        if len(del_list):
            del_cnt = 0
            for idx in del_list:
                a = np.delete(a, idx - del_cnt, axis=0)
                del_cnt += 1
        else:
            cnt += 1

        a = a.T

        if cnt >= 2:
            break

    for i in range(len(a)):
        r = ''
        for j in a[i]:
            if j == 1:
                r += '.'
            else:
                r += '#'
        print(r)


main()
