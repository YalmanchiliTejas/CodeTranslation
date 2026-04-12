n,x = map(int,input().split())
fi = x-1
aa = [1]
bb = [1]
a = 1
b = 1
for i in range(50):
    a = a*2 + 3
    b = b*2 + 1
    aa.append(a)
    bb.append(b)
    
def bu(lv , x):
    if lv == 0:
        return 1
    
    l = aa[lv-1]
    num = bb[lv-1]
    
    if x == 1:
        return 0
    elif x <= l+1:
        return bu(lv-1,x-1)
    elif x == l+2:
        return num +1
    elif x <= (l+1) * 2:
        return num + 1 + bu(lv-1,x-l-2)
    else:
        return num*2 + 1
    
print(bu(n,x))