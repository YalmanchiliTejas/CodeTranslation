# AtCoder Beginner Contest 062
# A - RGB Cards
r, g, b = map(int, input().split())
if (100*r+10*g+1*b) % 4 == 0:
    print('YES')
else:
    print('NO')