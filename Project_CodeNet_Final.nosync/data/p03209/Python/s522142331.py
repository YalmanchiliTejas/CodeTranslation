N, X = map(int, input().split())
result = [[]] * (N + 1)
result[0] = [1, 1] #[all-num, patty-num]
for i in range(1, N + 1):
    result[i] = [
        result[i - 1][0] * 2 + 3,
        result[i - 1][1] * 2 + 1,
    ]

def count_patty(idx, remain):
    if remain >= result[idx][0]:
        return result[idx][1]
    if remain <= 1:
        return 0
    ret = 0
    if remain >= result[idx][0] // 2 + 1:
        ret += result[idx - 1][1]
        ret += 1
        remain -= result[idx][0] // 2
    ret += count_patty(idx - 1, remain - 1)
    return ret

print(count_patty(N, X))