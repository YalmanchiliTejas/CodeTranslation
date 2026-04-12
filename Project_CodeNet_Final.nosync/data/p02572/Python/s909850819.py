n = int(input())
a = list(map(int, input().split()))


def mod(x):
    return x%(10**9+7)


sum_num = 0
ans = 0
for i in range(len(a)-1):
    idx = len(a)-i-1
    sum_num += a[idx]
    sum_num = mod(sum_num)
    ans += sum_num*a[idx-1]
    ans = mod(ans)
print(ans)
