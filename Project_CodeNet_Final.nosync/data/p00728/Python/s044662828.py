while True:
    n = int(input())
    if n == 0:
        break
    else:
        intlist = []
        minval = 1001
        maxval = -1
        for i in range(n): #calculate max and min values, create list of all values
            a = int(input())
            if a >= maxval:
                maxval = a
            if a <= minval:
                minval = a
            intlist.append(a)
        total = 0
        mincheck = False
        maxcheck = False
        for i in range(len(intlist)): #add numbers together
            if(intlist[i] == minval and mincheck == False): #ignore min value once
                mincheck = True
            elif(intlist[i] == maxval and maxcheck == False): #ignore max value once
                maxcheck = True
            else:
                total += intlist[i]
        print(total//(len(intlist) - 2)) #print avg
