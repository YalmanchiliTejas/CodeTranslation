datas = []

while True:
    n,s = (int(x) for x in input().split(","))
    if n == 0:
        break;
    datas.append((n,s))
datas = sorted(datas,key = lambda x:x[1],reverse=True)

while True:
    try:
        q = int(input())
        rank = 1
        score = datas[0][1]
    
        for n,s in datas:
            if score > s:
                score = s
                rank += 1
            if n == q:
                break
        print(rank)
    except:
        break
