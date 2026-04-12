N = input()
X = map(int, raw_input().split())
med = sorted(X)[N / 2 - 1:N / 2 + 1]
for v in X:
    if v <= med[0]:
        print med[1]
    else:
        print med[0]
