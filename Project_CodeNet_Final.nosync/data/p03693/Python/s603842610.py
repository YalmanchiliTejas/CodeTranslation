r, g, b = map(int, input().split())
s = int(100*r + 10*g + b)
t = s%4
if t == 0 :
 print('YES')
else :
 print('NO')