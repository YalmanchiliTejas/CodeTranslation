n = int(input())
a = list(map(int,input().split()))

max = (10 ** 9) + 7

#一列の総和
wa = 0
for i in range (n):
    wa += a[i]

#a11, a22, ...の総和
rem = 0
for i in range(n):
    rem += a[i]*a[i]

sum = ((wa*wa) - rem) // 2

ans = sum % max

print(ans)