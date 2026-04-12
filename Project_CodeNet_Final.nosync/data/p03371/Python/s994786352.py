a, b, c, x, y = map(int, input().split())
pmin = 10**10
for i in range(0, 2*max(x, y)+1, 2): # i枚のABピザを買う
    bx = max(0, x - i//2)
    by = max(0, y - i//2)
    pay = a*bx + b*by + c*i
    pmin = min(pmin, pay)


print(pmin)