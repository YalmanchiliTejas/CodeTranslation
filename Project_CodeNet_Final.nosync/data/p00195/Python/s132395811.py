end = 0
while end == 0 :
    shop = -1
    max_s = 0
    for i in range(5) :
        try :
            s1, s2 = map(int, input().split())
        except EOFError :
            end = 1
            break
    
        if s1 + s2 > max_s :
            max_s = s1 + s2
            shop = i
    
    if shop == 0 :
        shop_name = "A"
    elif shop == 1 :
        shop_name = "B"
    elif shop == 2 :
        shop_name = "C"
    elif shop == 3 :
        shop_name = "D"
    elif shop == 4 :
        shop_name = "E"
    if end == 0 :
        print(shop_name, max_s)
