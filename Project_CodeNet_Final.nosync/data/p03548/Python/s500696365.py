X, Y, Z = map( int, input().split() )

ans = 1
width = Z + Y + Z
while width + Y + Z <= X :
    width += Y + Z
    ans += 1

print( ans ) 