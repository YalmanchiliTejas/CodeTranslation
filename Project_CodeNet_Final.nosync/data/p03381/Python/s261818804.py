n = int(input())
x = list(map(int, input().split()))

y = list(sorted(x))
for xi in x:
    if xi <= y[n // 2 - 1]:
        print(y[n // 2])
    else:
        print(y[n // 2 - 1])