from itertools import accumulate
from sys import stdin


class ModInt:
    def __init__(self, x):
        self.x = x % MOD

    def __str__(self):
        return str(self.x)

    __repr__ = __str__

    def __add__(self, other):
        return ModInt(self.x + other.x) if isinstance(other, ModInt) else ModInt(self.x + other)

    def __sub__(self, other):
        return ModInt(self.x - other.x) if isinstance(other, ModInt) else ModInt(self.x - other)

    def __mul__(self, other):
        return ModInt(self.x * other.x) if isinstance(other, ModInt) else ModInt(self.x * other)

    def __truediv__(self, other):
        return (
            ModInt(self.x * pow(other.x, MOD - 2, MOD))
            if isinstance(other, ModInt)
            else ModInt(self.x * pow(other, MOD - 2, MOD))
        )

    def __pow__(self, other):
        return ModInt(pow(self.x, other.x, MOD)) if isinstance(other, ModInt) else ModInt(pow(self.x, other, MOD))

    __radd__ = __add__

    def __rsub__(self, other):
        return ModInt(other.x - self.x) if isinstance(other, ModInt) else ModInt(other - self.x)

    __rmul__ = __mul__

    def __rtruediv__(self, other):
        return (
            ModInt(other.x * pow(self.x, MOD - 2, MOD))
            if isinstance(other, ModInt)
            else ModInt(other * pow(self.x, MOD - 2, MOD))
        )

    def __rpow__(self, other):
        return ModInt(pow(other.x, self.x, MOD)) if isinstance(other, ModInt) else ModInt(pow(other, self.x, MOD))


def main():
    input = lambda: stdin.readline()[:-1]
    N = int(input())
    A = list(map(int, input().split()))

    a_ = map(ModInt, A)
    arr = list(accumulate(a_))
    ans = 0
    for i in range(N - 1):
        ans += A[i] * (arr[-1] - arr[i])
    print(ans)


MOD = 1000000007
main()
