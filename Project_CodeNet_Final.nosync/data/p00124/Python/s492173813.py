c = 0
while True:
    c +=1
    L = []
    num = int(input())
    if num == 0:
        break
    
    for i in range(num):
        name, w, l, d = input().split()
        w = int(w)
        d = int(d)
        L.append((i,name,w*3+d))
    
    L.sort(key=lambda x: (-x[2],x[0]))
    
    if c > 1:
        print()
        
    for l in L:
        print("{},{}".format(l[1], l[2]))
