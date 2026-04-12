N = int( input())
A = list( map( int, input().split()))
mod = 10 ** 9 + 7
total = sum( A )
ret = 0
for a in A:
  ret = ret + ( total - a ) * a
print( ( ret // 2 ) % mod )
