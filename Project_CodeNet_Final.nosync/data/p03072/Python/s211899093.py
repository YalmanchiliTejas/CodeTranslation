n = int(input())
list = list(map(int,input().split()))

def comparison(x,y):
    count1 = 0
    for t in range(0,y):
        if(x - list[t] >= 0):
            count1 = count1 + 1

    #print(count1)
    if(count1 == y):
        return 1
    else:
        return 0


answer = 1

for i in range(1,n):
    answer = answer + comparison(list[i],i)

print(answer)
