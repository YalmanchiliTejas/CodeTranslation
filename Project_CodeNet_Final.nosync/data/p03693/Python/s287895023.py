r, g, b = map( int, input().split() )
n = r * 100 + g * 10 + b
print( [ "NO", "YES" ][ n % 4 == 0 ] )