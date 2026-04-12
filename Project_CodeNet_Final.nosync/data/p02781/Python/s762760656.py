
'''
import math
n = int(input())
k = int(input())
b = len(str(n)) #桁数

ans = 0

for i in range(k, b + 1):
    in0 = i - 1 #0が入る可能性のあるところの桁数
    if in0 > 0:
        #print(in0, k - 1, in0 - k + 1)
        a = math.factorial(in0) // math.factorial(k - 1) // math.factorial(in0 - k + 1)
        ans += 9 * pow(9, k - 1)
        #print(9 * pow(9, a))
        print('a', 9 * pow(9, k - 1))
    else:
        ans += pow(9, i)
        print('b', pow(9, i))

print(ans)

for i in range(n + 1, pow(10, b)):
    #print(i)
    num = str(i)
    cnt = 0
    for j in range(b):
        if num[j] == '0':
            cnt += 1
    if cnt == b - k:
        ans -= 1
        #print(i, ans)
'''
'''
b = len(str(n)) #桁数
if b > k:
    a = math.factorial(b - 1) // math.factorial(k) // math.factorial(b - 1 - k)
    ans = a * pow(9, k)
else: 
    ans = 0

if k == 1:
    ans += int(str(n)[0])
elif k == 2:
    c = int(str(n)[0])
    for i in range(1, b): #2つめの1-9が入る場所
        for j in range(1, c + 1): #1つめの1-9の数字
            if j < c or i > 1:
                ans += 9
            else:
                #print(i, j, int(str(n)[i]))
                ans += int(str(n)[i])
else:
    c = [int(str(n)[i]) for i in range(b)] #桁数分離
    d = 1 #初めて0以外の数字が出てくる桁
    for i in range(1, b):
        if c[i] == 0:
            d += 1
        else:
            break
    if d < b: #n0000000とかでないとき
        ans += (c[0] - 1) * 81 * math.factorial(b - 1) // math.factorial(2) // math.factorial(b - 3) #1つめの数字がc[0]より小さい
        if b - d > 2:
            ans += 81 * math.factorial(b - d - 1) // math.factorial(2) // math.factorial(b - d - 3) #1つめの数字が一緒で2つめの数字の位置が低い場合
        ans += (c[d] - 1) * 9 * (b - d - 1) #1つめの数字が一緒で2つめの数字の位置が一緒で値が小さいとき
        #print(ans)
        #1つめと2つめの数字が一緒のとき
        for i in range(d + 1, b): #3つめの数字の位置
            for j in range(1, 10): #3つめの数字の値
                e = ['0' for _ in range(b)]
                e[0] = c[0]
                e[d] = c[d]
                e[i] = j
                f = ''
                for k in range(b):
                    f += str(e[k])
                f = int(f)
                if f <= n:
                    ans += 1






print(ans)
'''

'''
n = int(input())
k = int(input())
l = len(str(n))

dp = [[[0] * 2 for _ in range(k + 1)] for _ in range(l + 1)]
dp[0][0][0] = 1

for i in range(l):
    for j in range(k + 1):
        for m in range(2):
            d = int(str(n)[i])

            for nextd in range(10):
                nextj = j
                nextm = m

                if nextd != 0:
                    nextj += 1
                if nextj > k:
                    continue
                
                if m == 0:
                    if d < nextd:
                        continue
                    elif nextd < d:
                        nextm = 1
                
                dp[i + 1][nextj][nextm] += dp[i][j][m]

ans = dp[l][k][0] + dp[l][k][1]
print(ans)
'''

n = int(input())
k = int(input())
l = len(str(n))
a = [int(str(n)[i]) for i in range(l)]

dp = [[[0, 0] for _ in range(k + 1)] for _ in range(l)] #dp[i桁目][0でないのがj個][0: 未満, 1: 未満不確定]

dp[0][0][0] = 1         #0桁目で0でないのが0個、未満確定は0が入る1個
dp[0][0][1] = 0         #0桁目で0でないのが0個、未満不確定はa[0]!=0より0個
dp[0][1][0] = a[0] - 1  #0桁目で0でないのが1個、未満確定は1-a[0]-1のa[0]-1個
dp[0][1][1] = 1         #0桁目で0でないのが1個、未満不確定はa[0]の1個

#print(a)

for i in range(1, l):
    for j in range(k + 1):
        if j > 0 and a[i] != 0:
            #未満確定で0以外がj個のとき、0の1個
            #未満確定で0以外がj-1個のとき、1-9の9個
            #未満不確定で0以外がj個のとき、0の1個
            #未満不確定で0以外がj-1個のとき、1-a[i]-1のa[i]-1個
            dp[i][j][0] = dp[i-1][j][0] * 1 \
                        + dp[i-1][j-1][0] * 9 \
                        + dp[i-1][j][1] * 1 \
                        + dp[i-1][j-1][1] * (a[i] - 1)
            #未満不確定で0以外がj-1個のとき、a[i]の1個
            dp[i][j][1] = dp[i-1][j-1][1] * 1

        elif j > 0 and a[i] == 0:
            #未満確定で0以外がj個のとき、0の1個
            #未満確定で0以外がj-1個のとき、1-9の9個
            dp[i][j][0] = dp[i-1][j][0] * 1 \
                        + dp[i-1][j-1][0] * 9
            #未満確定で0以外がj個のとき、0の1個
            dp[i][j][1] = dp[i-1][j][1] * 1
        
        elif j == 0 and a[i] != 0:
            #未満確定で0以外がj個のとき、0の1個
            #未満不確定で0以外がj個のとき、0の1個
            dp[i][j][0] = dp[i-1][j][0] * 1 \
                        + dp[i-1][j][1] * 1
            #a[i] == 0のとき未満不確定はありえない
            dp[i][j][1] = 0
        elif j == 0 and a[i] == 0:
            #未満確定で0以外がj個のとき、0の1個
            dp[i][j][0] = dp[i-1][j][0] * 1
            #未満不確定で0以外がj個のとき、0==a[i]の1個
            dp[i][j][1] = dp[i-1][j][1] * 1
            

#print(dp)
print(dp[l-1][k][0] + dp[l-1][k][1])