class Dice:

    def __init__(self):
        self._top = 1
        self._front = 2
        self._side = 3
        self._sum = 1

    def to_north(self):
        tmp = self._top
        self._top = self._front
        self._front = 7 - tmp 
        self._sum += self._top

    def to_east(self):
        tmp = self._top
        self._top = 7 - self._side
        self._side = tmp
        self._sum += self._top

    def to_west(self):
        tmp = self._top
        self._top = self._side
        self._side = 7 - tmp
        self._sum += self._top

    def to_south(self):
        tmp = self._top
        self._top = 7 - self._front
        self._front = tmp
        self._sum += self._top

    def to_right(self):
        tmp = self._front
        self._front = self._side
        self._side = 7 - tmp
        self._sum += self._top

    def to_left(self):
        tmp = self._front
        self._front = 7 - self._side
        self._side = tmp
        self._sum += self._top

    def get_sum(self):
        return self._sum

if __name__ == '__main__':
    d = ['North', 'East', 'South', 'West', 'Right', 'Left']

    while True:
        dice = Dice()
        n = input()
        if n == 0:
            break

        for i in xrange(n):
            t = raw_input()
            if t == d[0]:
                dice.to_north() 
            elif t == d[1]:
                dice.to_east()
            elif t == d[2]:
                dice.to_south()
            elif t == d[3]:
                dice.to_west()
            elif t == d[4]:
                dice.to_right()
            elif t == d[5]:
                dice.to_left()

        print(dice.get_sum())