while True:
    n = input()
    if n==0:
        break
    list = []
    for i in range(0,n):
        tmp = input()
        list.append(tmp)
    list.sort()
    list.pop()
    list.pop(0)
    sum = 0
    for i in range(0,len(list)):
        sum += list[i]
    print sum/(n-2)