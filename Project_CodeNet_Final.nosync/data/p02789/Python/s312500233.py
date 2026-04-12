def get_ints():
    return map(int, input().split())

n, m = get_ints()
print('Yes' if n == m else 'No')
