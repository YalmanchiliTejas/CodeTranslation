while True:
    n = int(input())#n=0は終わり
    s = 0
    if n==0:
        break
    else:
        b=[]
        for i in range(n):
            a = int(input())#審判の点数
            b.append((a))
        b.sort()#全員分入力してからソート
        b.pop(n-1)#listが崩れるからz-1から抜いていく
        b.pop(0)
        s=sum(b) #bのリストのI番目をたす
        ave= s/(n-2)
        print(int(ave))
