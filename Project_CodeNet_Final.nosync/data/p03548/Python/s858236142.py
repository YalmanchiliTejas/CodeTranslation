#!/usr/bin/env python

def main():
    X, Y, Z = map(int, input().split(" "))

    # max_num = 0
    # for i in range(100000):
    #     if Y * i + Z * (i + 1) <= X:
    #         max_num = i
    #     else:
    #         break
    # print(max_num)

    print(int((X - Z) / (Y + Z)))

if __name__ == '__main__':
    main()
