import sys
X = int(input())
if not ( 1 <= X <= 9 ): sys.exit()

print('YES') if X == 3 or X == 5 or X == 7 else print('NO')