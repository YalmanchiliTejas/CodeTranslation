
import bisect
from array import array


def slow_solve(N, As):
    colors = []
    for a in As:
        if not colors:
            colors.append(a)
        else:
            if a <= colors[0]:
                colors.append(a)
            else:
                i = bisect.bisect_left(colors, a)
                colors[i-1] = a
        colors.sort()
        print(colors)
    return len(colors)


def solve(N, As):
    colors = array('I', [])
    for a in As:
        if not colors:
            colors.append(a)
        else:
            if a <= colors[0]:
                colors.insert(0, a)
            else:
                i = bisect.bisect_left(colors, a)
                colors[i - 1] = a
                j = i - 1
                while j + 1 < len(colors) and colors[j] > colors[j + 1]:
                    colors[j], colors[j + 1] = colors[j + 1], colors[j]
                    j += 1
        # print(colors)
    return len(colors)

#
# for _ in range(100):
#     import random
#     N = 10
#     As = [random.randint(1, 10) for _ in range(5)]
#     if slow_solve(N, As) != solve(N, As):
#         print("OUT")
#         print(N)
#         print(As)
#         input()
# print("OK")

if __name__ == "__main__":
    N = int(input())
    As = []
    [As.append(int(input())) for i in range(N)]
    print(solve(N, As))
