#RGBJを受け取る場所を作る
li = list(map(int,input().split()))
#下２桁を受け取る

b = li[1] * 10 + li[2]

if b%4 == 0:
    print('YES')
else :
    print('NO')
