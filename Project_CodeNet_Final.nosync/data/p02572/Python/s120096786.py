N = int(input())
list_A = list(map(int, input().split()))

threshold = 1000000007
tmp = sum(list_A[1:])
ans = 0
for i in range(N-1):
    if i == 0:
        ans += list_A[i] * tmp % threshold
    else:
        tmp = tmp - list_A[i]
        ans += (list_A[i] * tmp % threshold)
ans = ans % threshold
print(ans)