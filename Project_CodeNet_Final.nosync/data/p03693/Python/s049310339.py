r,g,b = map(int,input().split())
# 4の倍数は下２桁が4で割り切れる
number = [g,b]
print('YES') if int(''.join(map(str,number))) % 4 == 0 else print('NO')