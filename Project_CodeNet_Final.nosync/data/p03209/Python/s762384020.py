n, x = map(int, input().split())

total_counts = [1]
p_counts = [1]
for i in range(1, n + 1):
    total_counts.append(total_counts[-1] * 2 + 3)
    p_counts.append(p_counts[-1] * 2 + 1)


def count(x, n):
    if n == 0:
        return 1 if x > 0 else 0
    if x >= (total_counts[n] + 1) // 2:
        return p_counts[n - 1] + 1 + count(x - total_counts[n - 1] - 2, n - 1)
    else:
        return count(x - 1, n - 1)


print(count(x, n))