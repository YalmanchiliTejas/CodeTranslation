n,x,m = map(int,input().split())
mod = m
ans = 0
bit = [-1 for i in range(m)]
cycle = False
for i in range(n):
    if i == 0 :
        a = x
        bit[a] = i
        ans += a
    else:
        a = (a**2)% mod
        if bit[a] != -1:
            cy_st = bit[a]
            cy_fi = i -1
            cycle = True
            break
        else:
            bit[a] = i
            ans += a

if cycle:
    ans2 = 0
    b =  -1
    for j in range(cy_st):
        if j == 0 :
            b = x
            ans2 += b
        else:
            b = (b**2)% mod
            ans2 += b
    cy_num = ans - ans2
    cy_repe = (n-cy_st) // (cy_fi - cy_st + 1)
    ans3 = cy_num * cy_repe
    cy_amari = (n-cy_st) % (cy_fi - cy_st + 1)
    
    if b == -1:
        for j in range(cy_amari):
            if j == 0 :
                b = x
                ans3 += b
            else:
                b = (b**2)% mod
                ans3 += b
        
    else:
        for i in range(cy_amari):
            b = (b**2)% mod
            ans3 += b

    print(ans2+ans3)
else:
    print(ans)
