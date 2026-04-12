import math
from decimal import *

numbers = [int(i) for i in input().split()]

diff = numbers[1] - numbers[2]

if numbers[0] <= numbers[1]:
    print("1")
elif diff <= 0:
    print("-1")
else:
    print(math.ceil(Decimal(numbers[0] - numbers[1]) / diff) * 2 + 1)