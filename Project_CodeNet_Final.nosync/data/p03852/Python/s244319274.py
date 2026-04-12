import sys
import copy
import math
import bisect
import pprint
import bisect
from functools import reduce
from copy import deepcopy
from collections import deque

if __name__ == '__main__':
    s = input()
    if s == "a" or s == "i" or s == "u" or s == "e" or s == "o":
        print("vowel")
    else:
        print("consonant")
