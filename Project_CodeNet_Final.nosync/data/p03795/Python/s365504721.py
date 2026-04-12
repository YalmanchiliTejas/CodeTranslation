#!/usr/bin/python3
"""A-Restaurant"""

def main():
    N = int(input())
    bill = N * 800
    bill = bill - (N // 15) * 200
    print(bill)


if __name__ == '__main__':
    main()
