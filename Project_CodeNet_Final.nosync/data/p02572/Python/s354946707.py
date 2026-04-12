n = int(input())
t = 10**9+7
z = list(map(int,input().split() ))
_sum = 0
x = sum(z)
y = len(z)
for i in range(y-1):
    x = x-z[i]
    _sum += (z[i]*x)
        #print("_sum:"+str(_sum))
print(_sum%t)
    