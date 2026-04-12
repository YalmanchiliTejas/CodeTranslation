# coding: utf-8
# Here your code !
fin = False
while fin == False:
    lists = []
    times = int(input())
    if times == 0:
        fin == True
        break
    else:
        for i in range(times):
            a = int(input())
            lists.append(a)
        lists.remove(max(lists))
        lists.remove(min(lists))
        s = 0
        for i in lists:
            s+=i
        result = int(s/len(lists))
        print(result)
    
    