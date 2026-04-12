# -*- coding: utf-8 -*-
#スペース区切りの整数の入力
r,g,b = map(int,input().split())

a = r*100+g*10+b

#判定
if a%4 == 0:
    print("YES")
else:
    print("NO")