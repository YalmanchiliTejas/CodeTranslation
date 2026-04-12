#editorial参照
#再帰

m,y = map(int, input().split( ))
a = [1]
p = [1]
#あらかじめ作っておく
for i in range(m):
    a.append(a[i]*2+3)
    p.append(p[i]*2+1)
#場合分け、境界値

#入力と変数を一致させたが問題なかった
def f(m,y):#n,xにしないだけでバグる
    if m==0:
        return 0 if y<=0 else 1
    elif y <= 1+a[m-1]:
        return f(m-1,y-1)
    else:
        return p[m-1] + 1 + f(m-1, y-2 -a[m-1])

print(f(m,y))