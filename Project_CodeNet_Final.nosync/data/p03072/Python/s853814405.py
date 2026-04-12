n = int(input())
x = [int(i) for i in input().split()]
num,ans = 0,0
for i in range(n):
    if num<=x[i]: num,ans = x[i],ans+1
print(ans)