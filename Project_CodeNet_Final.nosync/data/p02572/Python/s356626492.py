#import 
#=input()
n=int(input())
#=map(int,input().split())
a=list(map(int,input().split()))
#=[list(map(int,input().split())) for _ in range()]
mod = 10 ** 9 + 7

sum = 0
for i in range(n):
    sum += a[i]

s = 0
for i in range(n-1):
    sum -= a[i]
    s = (s + a[i] * sum) % mod
print(s)