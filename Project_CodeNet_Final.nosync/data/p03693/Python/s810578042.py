r,g,b = map(int, input().split())
num = 100*r+10*g+b
print('YES' if num % 4 == 0 else 'NO')