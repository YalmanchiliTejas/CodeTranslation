import fileinput
import sys

a, b = [int(i) for i in fileinput.input().next().strip().split()]
if a > b:
    print "a > b"
    sys.exit(0)
if a < b:
    print "a < b"
    sys.exit(0)
if a == b:
    print "a == b"
    sys.exit(0)