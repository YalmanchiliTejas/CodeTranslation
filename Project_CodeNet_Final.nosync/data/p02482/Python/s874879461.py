import sys

def solve():
    a,b	= raw_input().split()
    a =	int(a)
    b =	int(b)

    if a > b:print "a > b"
    elif a < b:print"a < b"
    else: print "a == b"

if __name__ == "__main__":
    solve()