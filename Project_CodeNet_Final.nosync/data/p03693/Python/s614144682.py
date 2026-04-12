r,g,b=map(int,input().split())
X = r * 100 + g * 10 + b
if X % 4 == 0:
    print('YES')
else:
    print('NO')
    
