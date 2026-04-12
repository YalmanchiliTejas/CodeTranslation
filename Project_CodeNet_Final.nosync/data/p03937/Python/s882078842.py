h, w = map(int, input().split())
A = [input().count('#') for _ in range(h)]

print('Impossible' if h + w - 1 != sum(A) else 'Possible')