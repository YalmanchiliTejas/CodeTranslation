while True:
    mylist = []
    n = input()
    n = int(n)
    if n ==0:
        break
    for i in range(0,n):
        mylist.append(int(input()))
    mylistz = sorted(mylist)
    del mylistz[0]
    del mylistz[n-2]
    print(int(sum(mylistz))//(n-2))


