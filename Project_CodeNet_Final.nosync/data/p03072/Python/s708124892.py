N = int(input())
l = [int(i) for i in input().split(' ')]

total =0
for n,i in enumerate(l):
    if n == 0:
        total+=1
    else:
        flag = True
        for ii in l[:n]:
            if ii>i:
                flag = False
                break
        if flag:
            total+=1
print(total)
