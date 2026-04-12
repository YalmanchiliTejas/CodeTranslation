Z=[int(x) for x in input().split()]
a=100*Z[0]+10*Z[1]+Z[2]
if a%4==0:
    print('YES')
else:
    print('NO')