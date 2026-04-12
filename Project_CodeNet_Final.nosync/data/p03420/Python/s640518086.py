n, k = [int(i) for i in input().split()]

ans = 0
if k == 0:
    ans = n ** 2
else:
    for b in range(1, n+1):
        if b > k:
            loop_num = n // b #繰り返し回数
            loop_last = n - loop_num * b #ラストの途中で途切れてる部分
            ans += (b-k) * loop_num + max(0, loop_last - k + 1)

print(ans)
