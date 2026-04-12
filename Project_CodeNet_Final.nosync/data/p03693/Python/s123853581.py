r, g, b = map(int,input().split())
s = g * 10 + b
if s % 4 == 0 :
    print('YES')
else:
    print('NO')