class LCG:
    def __init__(self, a, b, c, x):
        self.a = a
        self.b = b
        self.c = c
        self.x = x
        self.count = 0

    def get_next(self):
        self.x = (self.a * self.x + self.b) % self.c
        self.count += 1
        return self.x

    def get_count(self):
        return self.count

if __name__ == "__main__":
    while True:
        n, a, b, c, x = map(int, input().split())
        if n == 0: break
        ran = LCG(a, b, c, x)
        reel = map(int, input().split())
        try:
            for r in reel:
                while x != r:
                    x = ran.get_next()
                    if ran.get_count() > 10000:
                        raise Exception
                else:
                    x = ran.get_next() # 同じrが連続した時の対応
            print(ran.get_count() - 1)
        except Exception:
            print(-1)