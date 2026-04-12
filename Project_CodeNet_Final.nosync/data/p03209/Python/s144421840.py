n, x = list(map(int, input().split()))

pb = 0
p = 0

def christmas(l, x) :
    global pb, p
    if l == 0 :
        if pb < x :
            pb += 1
            p += 1
    else :
        if pb < x :
            pb += 1
        if pb + 2**(l+1)-3 <= x :
            pb += 2**(l+1)-3
            p += 2**l-1
        elif pb < x :
            christmas(l-1, x)
        if pb < x :
            pb += 1
            p += 1
        if pb + 2**(l+1)-3 <= x :
            pb += 2**(l+1)-3
            p += 2**l-1
        elif pb < x :
            christmas(l-1, x)
        if pb < x :
            pb += 1

christmas(n, x)
print(p)