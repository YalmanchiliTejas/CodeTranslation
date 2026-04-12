a, b, c, x, y = map(int, input().split(' '))

c2 = c * 2
itr_end = max(x, y) + 1
results = []

for i in range(0, itr_end):
    # Cを2つi個だけ買って、残りはa、bで買う。ただし、マイナスの時(余っている時)は計算してはいけない。
    result = c2 * i
    if (x - i) > 0:
        result += a * (x - i)
    if (y - i) > 0:
        result += b * (y - i)

    results.append(result)

print(min(results))