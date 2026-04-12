h, w = map(int,input().split())
a = []
for i in range(h): #入力の時点で横を取り除く
    x = list(input())
    if x.count(".") == w:
        continue
    else:
        a.append(x)

n = len(a)
a = [list(x) for x in zip(*a)] #転置
x = 0 #popの調整

for i in range(w):
    if a[i-x].count(".") == n:
        a.pop(i-x)
        x += 1

a = [list(x) for x in zip(*a)] #転置して戻す

for i in range(len(a)): #出力
    for s in a[i]:
        print(s, end ="")
    print()