n = int(input())
yokolist = list(map(int, input().split()))

sum = ((sum(yokolist) % (10**9+7))**2 )% (10**9+7)

sum_2 = 0
for i in range(n):
    sum_2 += (yokolist[i]*yokolist[i] % (10**9+7))
    sum_2 = sum_2 % (10**9+7)

answer = (sum - sum_2) % (10**9+7)

if answer % 2 == 0:
    print(answer//2)
else:
    answer = answer + 10**9+7
    print(answer//2)
