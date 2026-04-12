# -*- coding: utf-8 -*-
a, b, c = map(int, raw_input().split())
# 出力
if (a*100+b*10+c)%4 ==0:
    print "YES"
else:
    print "NO"
