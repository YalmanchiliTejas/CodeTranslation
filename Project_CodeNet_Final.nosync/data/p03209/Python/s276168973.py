import math


# def burger_generator(n):
#     if n == 0:
#         return int("101", 2)
#     else:
#         lt = burger_generator(n-1)
#         x1 = 1 + (lt << 1)
#         length = int(math.log2(x1)) + 1
#         x1 = x1 + (lt << length + 1)
#         length = int(math.log2(x1)) + 1
#         return x1 + (1 << length)


def f(N, X):
    if X == 1:
        # print(1)
        return 0 if not N == 0 else 1
    elif X <= 1 + size[N - 1]:
        # print(2)
        return f(N - 1, X - 1)
    elif X == 2 + size[N - 1]:
        # print(3)
        return patty[N - 1] + 1
    elif X <= 2 + 2 * size[N - 1]:
        # print(4)
        return patty[N - 1] + 1 + f(N - 1, X - 2 - size[N - 1])
    elif X == 3 + 2 * size[N - 1]:
        # print(5)
        return 2 * patty[N - 1] + 1


N, X = map(int, input().split())
# burger = format(burger_generator(N), "b")
# print(burger[-K:].count("0"))
size, patty = [1], [1]
for i in range(N):
    size.append(size[i] * 2 + 3)
    patty.append(patty[i] * 2 + 1)
# for i in range(N):
#     print(size)
# for i in range(N):
#     print(patty)
print(f(N, X))
