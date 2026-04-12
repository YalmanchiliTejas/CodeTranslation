def getScore(d):
    return int(d[1]) * 3 + int(d[3])
    
isFirst = True

while 1:
    n = int(input())
    if n == 0:
        break
    if not isFirst:
        print()
    table = []
    for i in range(0,n):
        d = list(_ for _ in input().split())
        score = getScore(d)
        table.append((d[0],score))
    table.sort(key=lambda i:i[1],reverse=True)
    
    for n,s in table:
        print(str(n) + ',' + str(s))
    isFirst = False
