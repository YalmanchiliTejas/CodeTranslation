# -*- coding: utf-8 -*-

#スペース区切りの整数の入力
r, g, b = map(int, raw_input().split())
#入力値の連結
x = str(r)+str(g)+str(b)

#4の倍数か否かの確認
if int(x)%4 == 0:
    print 'YES'
else:
    print'NO'