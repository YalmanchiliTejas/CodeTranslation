n = int(input())
a = list(map(int,input().split()))

sum = 0
for i in a:
    sum += i

sum = sum * sum

for j in a:
    sum = sum - j*j

sum = (sum // 2) % 1000000007 
print(sum)