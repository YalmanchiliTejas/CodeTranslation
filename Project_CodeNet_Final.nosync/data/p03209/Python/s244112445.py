N, X = map(int, input().split())
Size = [1]
Patty = [1]

for i in range(51):
    Size.append(Size[-1] * 2 + 3)
    Patty.append(Patty[-1] * 2 + 1)


def count_p(n, x):
    if x == 0:
        return 0
    if n == 0:
        return min(x, 1)
    if (Size[n]+1) // 2 > x:
        return count_p(n-1, x-1)
    elif (Size[n]+1) // 2 == x:
        return Patty[n-1] + 1
    else:
        return Patty[n-1] + 1 + count_p(n-1, x - ((Size[n]+1) // 2))


print(count_p(N, X))