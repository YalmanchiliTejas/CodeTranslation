N,X = map(int, input().split())

burger_list = []
for i in range(N+1):
    if i == 0:
        burger_list.append([0,1])
    else:
        burger_list.append([2+burger_list[-1][0]*2,1+burger_list[-1][1]*2])

def pty(x,k,List):
    if x == 1:
        y = 0
    elif 1 < x <= sum(List[k-1])+1:
        y = 1
    elif x == 2+sum(List[k-1]):
        y = 2
    elif x == sum(List[k]):
        y = 4
    elif 2+sum(List[k-1]) < x <= 2+sum(List[k-1])*2:
        y = 3
    return y
        
ans = 0
k = N
while X > 0:
    n = pty(X,k,burger_list)
    if n == 0:
        if k == 0:
            ans += 1
        X = 0
    elif n == 2:
        ans += (burger_list[k-1][1]+1)
        X = 0
    elif n == 4:
        ans += burger_list[k][1]
        X = 0
    elif n == 1:
        X -= 1
        k -= 1
    elif n == 3:
        ans += (burger_list[k-1][1]+1)
        X -= (sum(burger_list[k-1])+2)
        k -= 1
print(ans)