n = int(input())
k = int(input())

r = 0
tp = n
while tp != 0:
    r += 1
    tp = tp//10

p = n//pow(10,r-1)

res = 0

if k == 1:
    res = (r-1)*9 + p
    print(res)

elif k == 2:
    if r <= 1:
        print(0)
        exit()
    if r >= 3:
        res = (r-1)*(r-2)*81//2
    
    res += (p-1)*9*(r-1)

    tmp = p*pow(10,r-1)
    for i in range(r-1):
        for j in range(1,10):
            if tmp + j*pow(10,i) <= n:
                res += 1
    
    print(res)
else:
    if r <= 2:
        print(0)
        exit()
    
    if r >= 4:
        res = pow(9,3)*(r-1)*(r-2)*(r-3)//6
    
    res += (p-1)*81*(r-1)*(r-2)//2

    tmp = p*pow(10,r-1)

    for i in range(r-1):
        for j in range(i+1,r-1):
            for w in range(1,10):
                for q in range(1,10):
                    if tmp + w*pow(10,i) + q*pow(10,j) <= n:
                        res += 1
    
    print(res)



