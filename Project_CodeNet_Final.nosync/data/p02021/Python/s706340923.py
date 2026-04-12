n = int(input())
li = list(map(int,input().split()))
fl = False
for i in range(1,200):
    task = 0
    if fl == True:
        break
    for a in li:
        task += a
        if task >= i:
            task -= i
        else:
            print(i-1)
            fl = True
            break
            
