def patty(n,x):
    if x == 0:
        return 0
    elif n == 0:
        #print(n,x,1)
        return 1
    elif x == 1 and n > 0:
        return 0
    num = 2 ** (n+2) - 3
    pre_num = 2 ** (n+1) - 3
    if x == num:
        #print(n,x,2 * patty(n-1,pre_num) + 1)
        return 2 * patty(n-1,pre_num) + 1
    elif x > pre_num + 1:
        #print(n,x,patty(n-1,pre_num) + 1 + patty(n-1,x - pre_num - 2))
        return patty(n-1,pre_num) + 1 + patty(n-1,x - pre_num - 2)
    elif x == pre_num + 1:
        #print(n,x,patty(n-1,pre_num) + 1)
        return patty(n-1,pre_num)
    else:
        #print(n,x,patty(n-1,x-1))
        return patty(n-1,x-1)

n, x = map(int,input().split())

print(patty(n,x))