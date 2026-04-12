r,g,b = map(int, input().split())
print('NO' if (10*g+b)%4 else 'YES')