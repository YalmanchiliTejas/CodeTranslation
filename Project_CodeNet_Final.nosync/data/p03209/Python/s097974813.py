N, X = map(int, input().split())

layer = [1]
num_of_P = [1]
result = 0

for _ in range(N-1):
    layer.append(layer[-1] * 2 + 3)
    num_of_P.append(num_of_P[-1] * 2 + 1)

layer.append(layer[-1] * 2 + 3)

while num_of_P:
    if layer[-1] // 2 + 1 > X:
        X -= 1
    else:
        X -= layer[-1] // 2 + 1
        result += num_of_P[-1] + 1

    del layer[-1]
    del num_of_P[-1]

print(result if X < 1 else result+1)
