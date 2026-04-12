while True:
    #審判の数
    n = int(input())
    if n == 0:
        break
    a = [0]*n               #空いてる配列
    for i in range(n):       #空いてる配列に点数を入れる
        s = int(input())
        a[i] = s
    tensu = (sum(a) - min(a) -max(a))/(len(a)-2) #一番でかい点数と一番小さい点数は一つずつ引いて平均
    print(int(tensu))        #平均点！
