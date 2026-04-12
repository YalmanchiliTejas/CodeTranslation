#!/usr/bin/env python3

def main():
    H, W = map(int, input().split())
    a = []
    for i in range(H):
        tmp = str(input())
        if "#" in tmp:
            a.append(tmp)
    binary = [1]*W
    for i in range(len(a)):
        for j in range(W):
            if a[i][j] == "#":
                binary[j] = 0
    for i in range(len(a)):
        tmp = ""
        for j, b in enumerate(binary):
            if b == 0:
                tmp += a[i][j]
        print(tmp)

if __name__ == '__main__':
    main()
