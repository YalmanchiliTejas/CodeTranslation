from sys import stdin
def I(): return int(stdin.readline().rstrip())

n = I()

print(n*800-int(n/15)*200)