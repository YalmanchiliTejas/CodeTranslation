n=int(input())
c=list(map(int, input().split())) 
s = sum(c)
m = 10**9+7
S = s%m
a = 0

for i in range(n-1):
    S -= c[i]
    a += c[i]*S
    a = a%m
print(a)