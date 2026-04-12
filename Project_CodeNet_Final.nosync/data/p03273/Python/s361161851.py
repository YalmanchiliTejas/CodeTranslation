H,W = map(int,input().split())

temp = [list(map(int,input().replace("#", "1").replace(".","0"))) for _ in range(H)]

cnt = 0


while cnt != 2:
    ans = []
    s = 0
    for row in temp:
        if sum(row) != 0:
            ans.append(row)
        else:
            s += 1
    if s == 0:
        cnt += 1
    else:
        cnt = 0
        
            
    temp = []
    for row in zip(*ans):
        temp.append(row)
    
    ans = []
    s = 0
    for row in temp:
        if sum(row) != 0:
            ans.append(row)
        else:
            s += 1
    if s == 0:
        cnt += 1
    else:
        cnt = 0
            
    temp = []
    for row in zip(*ans):
        temp.append(row)


for row in temp:
    res = list(map(str,row))
    res = ",".join(res).replace("1","#").replace("0",".").split(",")
    print("".join(res))
    

