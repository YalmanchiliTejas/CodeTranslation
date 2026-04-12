# -*- coding: utf-8 -*-

if __name__ == "__main__":
    r, g, b = map(str, input().split())

    if int(r+g+b) % 4 == 0:
        print("YES")
    else:
        print("NO")
