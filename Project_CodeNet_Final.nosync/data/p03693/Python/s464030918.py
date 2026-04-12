r, g, b = map(int, input().split())
1 <= r,g,b <= 9
sum = r*100 + g*10 + b
 
if sum % 4 == 0:
    print('YES')
else:
    print('NO')