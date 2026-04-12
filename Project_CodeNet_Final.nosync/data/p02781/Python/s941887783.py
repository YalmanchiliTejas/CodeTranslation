def f2(n):
    c = len(n)-1
    nn = n[1:]
    s = c*(c-1)//2 * 9*9 
    s += c * (int(n[0])-1)*9
    nn = str(int(nn))
    s += (len(nn)-1)*9 + int(nn[0])
    return s

n = input()
k = int(input())

if k == 1:
    print((len(n)-1)*9 + int(n[0]))
if k == 2:
    if len(n) >= 2:
        print(f2(n))
    else:
        print(0)
        
if k == 3:
    if len(n) >= 3:
        c = len(n)-1
        nn = n[1:]
        nn = str(int(nn))
        s = c*(c-1)*(c-2)//(3*2) * 9*9*9
        s += (int(n[0])-1) * c*(c-1)//2 * 9*9 
        if len(nn) >= 2:
            s += f2(nn)
        print(s)
    else:
        print(0)