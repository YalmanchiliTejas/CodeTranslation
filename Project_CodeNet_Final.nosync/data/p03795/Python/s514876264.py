import math
def main(n):
    x = 800 * n
    y = 0
    if n >= 15:
        y = 200 * math.floor(n / 15)
    print(x - y)

main(int(input()))