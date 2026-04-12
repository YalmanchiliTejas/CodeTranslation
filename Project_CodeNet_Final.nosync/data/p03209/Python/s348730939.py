class Burg:
    def __init__(self):
        self.lv = [2**(i+1) - 1 for i in range(51)]

    def make_burg(self, n, m):
        if n == 0:
            return 1, m - 1
        num = 4 * 2**n - 3
        if num <= m:
            return self.lv[n], m - num
        if m <= 1:
            return 0, 0
        a, b = self.make_burg(n - 1, m - 1)
        if b <= 1:
            return a + b, 0
        c, d = self.make_burg(n - 1, b - 1)
        return a + c + 1, max(0, d - 1)

n, x = map(int, input().split())

gen = Burg()
print(gen.make_burg(n, x)[0])