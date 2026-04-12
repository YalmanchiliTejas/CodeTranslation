n,x = map(int, input().split())

burger = [[1,1]]

for i in range(n):
    burger.append([burger[-1][0]*2+3,burger[-1][1]*2+1])

# レベルn, 下からx段, 食べるパティp枚
def eat(n,x):
    if n==0:
        if x>0:
            return 1
        else:
            return 0
    if x < 1:
        return 0
    if 1 <= x <= 1+burger[n-1][0]:
        return eat(n-1,x-1)
    if x == 2 + burger[n-1][0]:
        return burger[n-1][1]+1
    if x>2+burger[n-1][0]:
        return eat(n-1,x-2-burger[n-1][0])+burger[n-1][1]+1


print(eat(n,x))
