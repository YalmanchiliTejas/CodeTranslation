n = int(input())
L = list(map(int,input().split()))
mod = 10**9+7
sum1 = sum(L)

a = sum1*sum1
li = [x**2 for x in L]

b = sum(li)

print(((a-b)//2)%mod)