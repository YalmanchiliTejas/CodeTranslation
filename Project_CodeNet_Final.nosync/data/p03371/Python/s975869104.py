a, b, c, x, y = map(int, input().split())
pmin = 10**10
for i in range(max(x, y)+1): # 2i枚のABピザを買う
    bx = max(0, x - i)
    by = max(0, y - i)
    pay = a*bx + b*by + 2*c*i
    pmin = min(pmin, pay)


print(pmin)