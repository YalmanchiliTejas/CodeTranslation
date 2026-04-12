# Aizu Problem 0195: What is the Most Popular Shop in Tokaichi?
#
import sys, math, os

# read input:
PYDEV = os.environ.get('PYDEV')
if PYDEV=="True":
    sys.stdin = open("sample-input.txt", "rt")


while True:
    most = 0
    shop = 'A'
    a, b = [int(_) for _ in input().split()]
    if a == b == 0:
        break
    most = a + b
    for s in range(4):
        a = sum([int(_) for _ in input().split()])
        if a > most:
            most = a
            shop = chr(66 + s)
    print(shop, most)
            