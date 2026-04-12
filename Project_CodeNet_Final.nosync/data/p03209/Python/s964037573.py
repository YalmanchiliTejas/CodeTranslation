N, X = map(int, input().split())

size_table = [1] * 51
pate_table = [1] * 51

for i in range(1, 51):
    size_table[i] = size_table[i-1] * 2 + 3
    pate_table[i] = pate_table[i-1] * 2 + 1

def calc(N, X):
    if X <= 0:
        return 0
    if size_table[N] <= X:
        return pate_table[N]
    r = 0
    r += calc(N - 1, X - 1)
    if (size_table[N - 1] + 1) < X:
        r += 1
    r += calc(N - 1, X - size_table[N - 1] - 2);
    return r

print(calc(N, X))
