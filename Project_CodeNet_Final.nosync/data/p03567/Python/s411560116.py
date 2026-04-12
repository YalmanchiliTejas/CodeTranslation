S = str(input())
Slist = list(S)
flag = False
for i in range(len(Slist)-1):
    st = Slist[i] + Slist[i+1]
    if(st == "AC" and flag == False):
        print('Yes')
        flag = True
if(flag == False):
    print('No')