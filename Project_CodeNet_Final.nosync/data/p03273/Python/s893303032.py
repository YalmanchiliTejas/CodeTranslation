# -*- coding: utf-8 -*-

def main():
    h, w = map(int, input().split())
    lines = [l for l in [input() for _ in range(h)] if l != '.' * w]
    lines2 = [''] * len(lines)
    for i in range(w):
        f = False
        for l in lines:
            if l[i] != '.':
                f = True
                break
        if f:
            for j, l in enumerate(lines):
                lines2[j] = lines2[j] + l[i]

    for l in lines2:
        print(l)


if __name__ == '__main__':
    main()
