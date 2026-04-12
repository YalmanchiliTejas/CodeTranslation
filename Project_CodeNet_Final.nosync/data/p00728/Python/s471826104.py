import sys

while True:
    n = int(input())
    if n == 0:
        break
    print( int( sum( sorted( [int(input()) for x in range(0, n)] )[1:-1] )/(n-2) ) )

    