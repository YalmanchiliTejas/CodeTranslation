n, x = map(int, input().split())

layers, putties = [1], [1]
for i in range(n):
        layers.append(layers[-1] * 2 + 3)
        putties.append(putties[-1] * 2 + 1)

def count_putties(N, X):
        if N == 0:
                return 1 if X > 0 else 0
        elif X <= layers[N-1] + 1:
                return count_putties(N-1, X-1)
        else:
                l = putties[N-1] + 1
                return l + count_putties(N-1, X-(layers[N-1] + 2))

print(count_putties(n, x))