n = int(input())
li = list(map(int,input().split()))

num = 0
max1 = li[0]
for i in range(n):
    if li[i] >=max1:
        max1 = li[i]
        num += 1

print(num)