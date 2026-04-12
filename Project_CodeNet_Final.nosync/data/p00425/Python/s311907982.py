n = int(input())
while (n!=0):
    wlist = []
    for i in range(n):
        wlist.append(str(input()))
    ufr = {"u":1 ,"f":2, "r":3}
    up = 1
    for w in wlist:
        tmp = 0
        if (w == "North"):
            tmp = ufr["u"]
            ufr["u"] = ufr["f"]
            ufr["f"] = 7-tmp
        elif (w == "East"):
            tmp = ufr["r"]
            ufr["r"] = ufr["u"]
            ufr["u"] = 7-tmp
        elif (w == "West"):
            tmp = ufr["u"]
            ufr["u"] = ufr["r"]
            ufr["r"] = 7-tmp
        elif (w=="South"):
            tmp = ufr["f"]
            ufr["f"] = ufr["u"]
            ufr["u"] = 7-tmp
        elif (w=="Right"):
            tmp = ufr["f"]
            ufr["f"] = ufr["r"]
            ufr["r"] = 7-tmp
        else:
            tmp = ufr["r"]
            ufr["r"] = ufr["f"]
            ufr["f"] = 7-tmp
        up += ufr["u"]  
    print(up)   
    n=int(input())
