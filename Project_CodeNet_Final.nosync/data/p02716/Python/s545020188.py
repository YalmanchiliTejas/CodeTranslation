N = int(input())
A = list(map(int, input().split()))

if  N % 2 == 0:
    M =  N // 2
    even_A = [A[i* 2] for i in range(M)]
    odd_A = [A[i* 2 + 1] for i in range(M)]
    even_sum = []
    _sum = 0
    for a in even_A:
        _sum += a
        even_sum.append(_sum)
    odd_sum = []
    _sum = 0
    for a in odd_A:
        _sum += a
        odd_sum.append(_sum)
    ans = max(odd_sum[-1], even_sum[-1])
    for i in range(M):
            x = even_sum[i] + odd_sum[-1] - odd_sum[i]
            ans = max(ans, x)
    print(ans)
    exit()
M =  N // 2
# evenが元一つ多い
even_A = [A[i* 2] for i in range(M+1)]
odd_A = [A[i* 2 + 1] for i in range(M)]
even_sum = []
_sum = 0
for a in even_A:
    _sum += a
    even_sum.append(_sum)
odd_sum = []
_sum = 0
for a in odd_A:
    _sum += a
    odd_sum.append(_sum)
# 全て奇数
all_even = even_sum[-1] - min(even_A)
diff_odd_even = [odd_sum[k] - even_sum[k+1] for k in range(M)]
diff_max_odd_even = []
diff_max = diff_odd_even[-1]
for k in range(M):
    diff_max = max(diff_max, diff_odd_even[-k-1])
    diff_max_odd_even.append(diff_max)
diff_max_odd_even.reverse()

ans = all_even
for i in range(M):
        x = even_sum[i] + odd_sum[-1] - odd_sum[i]
        y = odd_sum[i] + even_sum[-1] - even_sum[i+1]
        z = even_sum[i] + - odd_sum[i] + even_sum[-1] + diff_max_odd_even[i]
        ans = max(ans, x, y, z)
print(ans)

