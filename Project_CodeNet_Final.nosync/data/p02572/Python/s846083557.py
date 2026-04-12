n = int(input())
M = 1000000007
a = input().split()
sum = 0
sq_sum = 0
for x in a:
    y = int(x)
    sum += y
    sq_sum += (y*y)
sum = sum * sum
ans = abs(sum - sq_sum)//2
ans = (ans + M) % M
ans = int(ans)
print(ans)
