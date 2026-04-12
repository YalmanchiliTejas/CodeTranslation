import math


nums=int(input())

cost=800*nums

save=200*(math.floor(nums/15))

print(cost-save)
