class Dice(object):
    def __init__(self):
        self.u = 1
        self.f = 2
        self.r = 3
        self.l = 4
        self.d = 6
        self.b = 5

    def rotate(self, d):
        cu, cf, cr, cl, cd, cb = self.u, self.f, self.r, self.l, self.d, self.b
        if d == 0:  # N
            self.u, self.f, self.d, self.b = cf, cd, cb, cu
        elif d == 1: # E
            self.u, self.r, self.d, self.l = cl, cu, cr, cd
        elif d == 2: # W
            self.u, self.r, self.d, self.l = cr, cd, cl, cu
        elif d == 3: # S
            self.u, self.f, self.d, self.b = cb, cu, cf, cd
        elif d == 4: # R
            self.f, self.r, self.b, self.l = cr, cb, cl, cf
        elif d == 5: # L
            self.f, self.r, self.b, self.l = cl, cf, cr, cb


while True:
    n = int(input())
    if n == 0:
        break

    dice = Dice()
    count = 1
    for _ in range(n):
        s = input()[0]
        if s == "N":
            dice.rotate(0)
        elif s == "E":
            dice.rotate(1)
        elif s == "W":
            dice.rotate(2)
        elif s == "S":
            dice.rotate(3)
        elif s == "R":
            dice.rotate(4)
        elif s == "L":
            dice.rotate(5)
        else:
            pass
        count += dice.u
    print(count)
