def q39(n, h):
    count = 1
    for i in range(1, n):
        if h[i] >= max(h[:i]):
            count += 1
    return count


N = int(input())
H = [int(i) for i in input().split()]
print(q39(N, H))