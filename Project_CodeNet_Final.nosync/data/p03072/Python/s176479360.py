N = int(input())
Hs = list(map(int, input().split(' ')))

result = list(filter(lambda h: h, [Hs[i] == max(Hs[:i + 1]) for i in range(len(Hs))]))
print(len(result))
