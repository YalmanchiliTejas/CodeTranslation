import itertools
import sys
import math
import numpy as np
from collections import deque
from itertools import combinations
from functools import reduce
from functools import lru_cache
sys.setrecursionlimit(10**9)

def main():
    S = input()
    f = S[0] == S[1] == S[2]

    print("No" if f else "Yes")




if __name__ == "__main__":
  main()
