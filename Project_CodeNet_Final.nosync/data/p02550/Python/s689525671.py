n,x,m = list(map(int,input().split()))

if x == 0:
    ans = 0
else:
    ans = x % m
dicNum = dict()
dicSum = dict()
dicNum[x] = 1
dicSum[1] = x
dicSum[0] = 0

for i in range(2,n+1):
    b = x
    x = x**2 % m
    if x in dicNum.keys():
        t = i - dicNum[x]
        zan = n - i + 1
        k = zan // t
        ans += (dicSum[i-1] - dicSum[dicNum[x]-1]) * k
        if zan% t != 0:
            zan = zan % t
            ans += dicSum[dicNum[x] - 1 + zan] - dicSum[dicNum[x]-1]
        break
    else:
        ans += x
        dicSum[i] = ans
        dicNum[x] = i

print(ans)