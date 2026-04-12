import math
n, k = map(int,input().split())

count = 0
for b in range(max(k,1),n+1):
    if n % b != 0:
        t = math.ceil(n/b)
    else:
        t = int(n/b) + 1
    if n % b >= k:
        count += (b-k)*t - ((t*b-1)-n)
    else:
        count += (b-k)*(t-1)

#k=0のとき,n=0を除外する
if k ==0:
    count -= (n-k)


print(count)
