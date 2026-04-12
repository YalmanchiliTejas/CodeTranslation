r,g,b = [int(i) for i in input().split()]
print('YES' if (100*r+10*g+b)%4 == 0 else 'NO')