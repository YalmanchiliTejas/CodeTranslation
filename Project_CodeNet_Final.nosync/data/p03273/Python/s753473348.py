h, w = map(int, input().split())

li = []
for i in range(h):
    str = list(input())  # 1文字区切りでリスト格納
    li.append(str)

flg = True


# 縦に見ていく
for i in range(w):
    flg2 = True
    for j in range(h):
        if li[j][i] == "#":
            flg2 = False
            break
    
    if flg2:
        for j in range(h):
            li[j][i] = "a"

for i in range(h):
    flg2 = True
    for j in range(w):
        if li[i][j] == "#":
            flg2 = False
            break
    if flg2:
        for j in range(w):
            li[i][j] = "a"

    
for i in range(h):
    flg3 = False
    for j in range(w):
        if li[i][j] != "a":
            print(li[i][j], end ="")
            flg3=True
    
    if flg3:
        print()
