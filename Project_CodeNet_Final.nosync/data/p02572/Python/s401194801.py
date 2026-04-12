n = int(input())
a = list(map(int, input().split()))

da = [a[n-1] for i in range(n)]
for i in range(n-2, -1, -1):
    da[i] = da[i+1] + a[i]
sum = 0
for i in range(n-1):
    # print (str(a[i]) + " : " + str(da[i+1]))
    sum += a[i] * da[i+1]
    sum %= 1000000007
# print(da)
print(sum)