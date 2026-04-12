a_yen , b_yen, c_yen , a_count,b_count = map(int,input().split())

abmax = max(a_count, b_count)
c_count = 0
kouhopiza = a_yen * a_count + b_yen * b_count + c_yen * c_count

while c_count <= 2*abmax:
    if kouhopiza > a_yen * a_count + b_yen * b_count + c_yen * c_count and a_count > -1 and b_count > -1:
        kouhopiza = a_yen * a_count + b_yen * b_count + c_yen * c_count
    elif a_count > -1 and b_count < 0:
        if kouhopiza > a_yen * a_count + c_yen * c_count:
            kouhopiza = a_yen * a_count + c_yen * c_count
    elif a_count < 0 and b_count > -1:
        if kouhopiza > b_yen * b_count + c_yen * c_count:
            kouhopiza = b_yen * b_count + c_yen * c_count
        
    c_count = c_count + 2
    a_count = a_count - 1
    b_count = b_count - 1
print(kouhopiza)


