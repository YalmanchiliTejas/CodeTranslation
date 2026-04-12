while True:
    n = int(raw_input())
    if n == 0:
        break
    else:
        l = []
        for i in range(n):
            num = int(raw_input())
            l.append(num)
            l.sort()
        l = l[1:-1]
        ave = float(sum(l))/len(l)
        print int(ave)
    
    