# -*- coding: utf-8 -*-

def main():

    N = int(input())

    x = N * 800
    y = (N // 15) * 200

    ans = x - y

    print(ans)


if __name__ == "__main__":
    main()