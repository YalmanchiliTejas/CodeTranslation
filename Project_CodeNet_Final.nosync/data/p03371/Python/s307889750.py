a,b,c,x,y = list(map(int,input().split()))
cost = []
tmp = 0
i = 0
# i == Cの数 (Cの倍額でA*1+B*1)
while i <= max(x,y) :
    tmp += i * 2 * c
    tmp += max(x-i,0)*a + max(y-i,0) * b
    cost.append(tmp)
    i += 1
    tmp = 0

print(min(cost))
    
