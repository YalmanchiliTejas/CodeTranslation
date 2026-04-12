N = int(input())

y = N // 15
x = N * 800

if y >= 1:
    print( x - (y * 200))
else:
    print(x)