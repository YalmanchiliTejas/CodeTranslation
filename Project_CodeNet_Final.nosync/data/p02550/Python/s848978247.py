N, X, M = map(int, input().split())
count_memo = [-1] * 10**6 # 回数のメモ
num_memo = [0] #1インデックスるにする

a = X
count = 1
count_memo[a] = count
num_memo.append(a)
for i in range(1, N):
    a = a**2 % M
    if count_memo[a] == -1:
        count += 1
        count_memo[a] = count
        num_memo.append(a)
    else:
        break

if count == N:
    answer = sum(num_memo)
else:
    # 周期に入るまでの回数と合計
    count_before_cycle = count_memo[a] - 1
    sum_before_cycle = sum(num_memo[:count_before_cycle+1])
    # 1周期の数と合計
    count_cycle = count - count_before_cycle
    sum_cycle = sum(num_memo[count_before_cycle+1:])
    # 残りのサイクルの数と合計
    cycle_count = (N - count) // count_cycle
    sum_after_cycle = sum_cycle * cycle_count
    # あまりの数と合計
    remain_count =  (N - count) % count_cycle
    sum_remain = sum(num_memo[count_before_cycle+1:count_before_cycle+1 + remain_count])

    answer = sum_before_cycle + sum_cycle + sum_after_cycle + sum_remain

print(answer)

