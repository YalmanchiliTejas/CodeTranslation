n,x,m = map(int, input().split())

lm = [x]
a = x

zero = 0
for i in range(m):
    a = a ** 2 % m
    if a == 0:
        zero = 1
        break
    lm.append(a)

if zero == 1:
    if n < len(lm):
        print(sum(lm[:n]))
    else:
        print(sum(lm))
        

else:
    last = lm[m]
    for i in range(1, m+1):
        if lm[m-i] == last:
            syuki = i
            break

    for i in range(2, m//syuki + 2):
        if m - i*syuki < 0:
            amari = (m+1) % syuki
        if lm[m - i*syuki] != last:
            amari = m - (i-1) * syuki + 1
            break

    l1 = lm[:amari]
    l2 = lm[amari:amari + syuki]


    if n <= amari:
        print(sum(l1[:n]))

    else:
        n -= amari
        print(sum(l1) + sum(l2) * (n//syuki) + sum(l2[:(n%syuki)]))