n = int(input())
li = list(map(int,input().split()))
count = 0
sum = sum(li)
for i in range(n-1):
    sum -= li[i]
    count += (sum)*li[i]%(10**9+7)
print(count%(10**9 + 7))