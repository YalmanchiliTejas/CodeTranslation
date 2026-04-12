#C - Half and Half
#いつもの
a,b,c,x,y = list(map(int,input().split()))
#共通部分の枚数入れ
common = 0
#回答
ans = 0
#共通する部分をABピザの分割にするかどうかを判定する
if(x < y):
    common = x
else:
    common = y
if(c*2 < a+b):
    ans += c*2*common
else:
    ans += (a+b)*common
#どちらか片方多い部分をABピザの分割で買うかAもしくはB単品で買うか判定する
if(x < y):
    if(b < c*2):
        ans += b * (y-common)
    else:
        ans += c*2 * (y-common)
else:
    if(a < c*2):
        ans += a * (x-common)
    else:
        ans += c*2 * (x-common)
print(ans)
