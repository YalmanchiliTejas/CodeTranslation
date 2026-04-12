n = (int)(input())
tmp = 0
ex = 0
LIST = list(map(int,input().split()))
for h in LIST:
    if tmp<=h:
        tmp=h
        ex +=1
print(ex)