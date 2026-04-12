# 演習１－１２
while True:
    a = int(input())
    if a == 0:
        break
    else:
        li = [0]*a
        for i in range(a):
            li[i] = int(input())
        li_sort = sorted(li)
        del li_sort[0]
        del li_sort[-1]
        print(int(sum(li_sort)/len(li_sort)))
