# import bisect
# import copy
# import fractions
# import math
# import numpy as np
# from collections import Counter, deque
# from itertools import accumulate,permutations, combinations,combinations_with_replacement,product

def resolve():
    x,y,z=map(int,input().split())
    x=x-z
    print(x//(y+z))

resolve()