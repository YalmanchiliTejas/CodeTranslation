r,g,b = map(str,input().split())
x = int(r+g+b)
print('YES' if x % 4 == 0 else 'NO')
