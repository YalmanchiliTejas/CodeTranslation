a,b,c=map(int, input().split())  #複数数値入力　「A B」みたいなスペース空いた入力のとき
d = int(str(a)+str(b)+str(c)) % 4
if d != 0:
    print('NO')
else:
    print('YES')