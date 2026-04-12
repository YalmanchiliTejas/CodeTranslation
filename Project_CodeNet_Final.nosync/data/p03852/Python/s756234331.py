#!/usr/bin/python

import sys

VOWEL = ["a", "e", "i", "o", "u"]

def main(argv):
    for line in sys.stdin:
        line = line.strip("\n")
        if line in VOWEL:
            print "vowel"
        else:
            print "consonant"

if __name__ == "__main__":
    main(sys.argv)