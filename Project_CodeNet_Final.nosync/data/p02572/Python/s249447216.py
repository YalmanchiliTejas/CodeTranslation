n = int( input() )
a = list( map( int, input().split() ) )

MOD = 10 ** 9 + 7

sum_a = 0
for a_i in a:
    sum_a = ( sum_a + a_i ) % MOD

ans = 0
for i in range( n ):
    sum_a = ( sum_a - a[ i ] ) % MOD
    ans = ( ans + a[ i ] * sum_a % MOD ) % MOD

print( ans ) 