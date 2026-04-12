N = int(input())
num = [int(i) for i in input().split()]

sum = [0]
sum1 = 0
for i in range(N):
    sum.append(num[i] + sum[i])

for x in range(N):
    if((num[x] * sum[x])//(10**9 + 7)>= 1 ):
        sum1 += num[x]*sum[x] - ((num[x] * sum[x])//(10**9 + 7))*(10**9 + 7)
    else:
        sum1 += num[x]*sum[x]

print(sum1 - (sum1//(10**9 + 7))*(10**9 + 7) )
