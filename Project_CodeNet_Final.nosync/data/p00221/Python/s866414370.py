# Aizu Problem 0221: Fizz Buzz

import sys, math, os, struct

# read input:
PYDEV = os.environ.get('PYDEV')
if PYDEV=="True":
    sys.stdin = open("sample-input.txt", "rt")


def valid(k, a):
    if k % 15 == 0: 
        return a == "FizzBuzz"
    elif k % 3 == 0:
        return a == "Fizz"
    elif k % 5 == 0:
        return a == "Buzz"
    else:
        return a == str(k)

    
def fizz_buzz(m, n, A):
    players = list(range(1, m + 1))
    p = 0
    k = 0
    while len(A) > 0:
        k += 1
        a = A.pop(0)
        if valid(k, a):
            p = (p + 1) % m
        else:
            if len(players) == 0:
                print()
                return
            players.pop(p)
            if len(players) == 1:
                break
            m -= 1
            p %= m
    print(' '.join([str(p) for p in players]))
    
    
while True:
    m, n = [int(_) for _ in input().split()]
    if m == 0:
        break
    A = [input().strip() for _ in range(n)]
    fizz_buzz(m, n, A)