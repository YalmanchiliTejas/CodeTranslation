n = int(input())
a = [int(input()) for _ in range(n)]
num = int(n/2)
a.sort(reverse = True)
x = []
y = []
if n%2 == 0:
    result = 0
    x = a[:num]
    y = a[num:]
    result += sum(x)*2 - x[-1]
    result -= sum(y)*2 - y[0]
    print(result)
else:
    x = a[:num]
    y = a[num+1:]
    mid = a[num]
    result_1 = int(sum(x)*2 + mid - x[-1] - sum(y)*2)
    result_2 = int(sum(x)*2 - sum(y)*2 -mid + y[0])
    print(max(result_1, result_2))