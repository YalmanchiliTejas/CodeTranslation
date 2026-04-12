def mondai(n, k):

    keta = 0
    a = n
    b = []
    ans = 0
    d = 0

    while a >= 10:
        c = a % 10
        b.append(c)
        a = a // 10
        keta = keta + 1
    
    for i in range(len(b)):
        d = d + b[i] * (10 ** i)

    if k == 1:
        ans = keta * 9 + a

    elif k == 2:
        if keta == 0:
            ans = 0
        elif keta == 1:
            ans = keta * 9 * (a - 1) + mondai(d, 1)
        else:
            for i in range(1, keta):
                ans = ans + i * 81
            ans = ans + keta * 9 * (a - 1) + mondai(d, 1)
        
    else:
        if keta == 0 or keta == 1:
            ans = 0
        elif keta == 2:
            ans = keta * 81 * (a - 1) + mondai(d, 2)
        
        else:
            for i in range(2, keta):
                ans = ans + i * (i - 1) / 2 * 9 * 9 * 9
            ans = ans + keta * (keta - 1) / 2 * 81 * (a - 1) + mondai(d, 2) 
            
                
    return ans

n = int(input())
k = int(input())

ans = int(mondai(n, k))
    
print(ans)