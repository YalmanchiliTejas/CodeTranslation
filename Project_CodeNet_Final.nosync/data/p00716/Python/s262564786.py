import sys


def simple(money, rate, charge, year):
    temp = 0
    for i in xrange(year):
        temp += int(money * rate)
        money -= charge
    return money + temp

def compound(money, rate, charge, year):
    temp = 0
    for i in xrange(year):
        money += int(money * rate)
        money -= charge
    return money + temp

m = int(sys.stdin.readline())
for z in xrange(m):
    money = int(sys.stdin.readline())
    year = int(sys.stdin.readline())
    n = int(sys.stdin.readline())
    result = []
    for i in xrange(n):
        simple_or_compound, rate, charge = sys.stdin.readline().split()
        simple_or_compound = int(simple_or_compound)
        rate = float(rate)
        charge = int(charge)
        if simple_or_compound == 0:
            result.append(simple(money, rate, charge, year))
        else:
            result.append(compound(money, rate, charge, year))
    result.sort()
    print result[-1]