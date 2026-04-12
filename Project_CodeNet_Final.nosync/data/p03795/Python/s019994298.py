""" abc055_a """

import sys

H = pow(10, 9) + 7

def _main():
    _n = int(sys.stdin.readline())

    _x = 800 * _n
    _y = int(_n/15) * 200

    print(_x - _y)

if __name__ == '__main__':
    _main()
