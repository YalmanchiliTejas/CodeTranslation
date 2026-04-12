import sys

def readline():
    return raw_input()

class Dice:
    def __init__(self):
        # [Top,East,North,West,South,Bottom]
        self.sides = [1,3,5,4,2,6]

    def move(self,direction):
        dirdir = { 'North': ([0,2,5,4],[4,0,2,5]),
                   'South': ([0,2,5,4],[2,5,4,0]),
                   'East':  ([0,1,5,3],[3,0,1,5]),
                   'West':  ([0,1,5,3],[1,5,3,0]),
                   'Left':  ([1,4,3,2],[4,3,2,1]),
                   'Right': ([1,4,3,2],[2,1,4,3])
                   }
        def _move(directive):
            b = self.sides[:]
            for i in range(0,4):
                b[directive[0][i]] = self.sides[directive[1][i]]
            self.sides = b
        _move(dirdir[direction])
    
    def top(self):
        return self.sides[0]

while 1:
    n = int(readline())
    if n == 0:
        exit(0)
    d = Dice()
    ans = d.top()
    for i in range(0,n):
        direction = readline()
        d.move(direction)
        ans += d.top()
    print ans