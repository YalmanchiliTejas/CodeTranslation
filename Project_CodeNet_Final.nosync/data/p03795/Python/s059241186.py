#!/usr/bin/python

import sys

def main(argv):
    for line in sys.stdin:
        n = int(line)
        x = n * 800
        y = int(n / 15) * 200
        print x - y

if __name__ == "__main__":
    main(sys.argv)