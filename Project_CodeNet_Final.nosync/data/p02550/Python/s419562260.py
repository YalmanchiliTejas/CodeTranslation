n, x, m = map( int, input().split() )
# n, x, m = 10000000000, 10, 99959

found = [ -1 for _ in range( m ) ]
summation = [ 0 ]
a = x
length, loop_s, s_0, start = -1, -1, -1, -1
for i in range( n ):
    if found[ a ] > -1:
        length = i - found[ a ]
        loop_s = summation[ i ] - summation[ found[ a ] ]
        start = found[ a ]
        s_0 = summation[ start ]
        # print( length, loop_s, s_0, a, start )
        break
    else:
        found[ a ] = i
    # print( i, a )
    summation.append( summation[ -1 ] + a )
    a = ( a * a ) % m

if length < 0:
    print( summation[ n ] )
else:
    times = ( n - start ) // length
    rem = ( n - start ) % length
    rem_s = summation[ start + rem ] - s_0
    print( s_0 + loop_s * times + rem_s )