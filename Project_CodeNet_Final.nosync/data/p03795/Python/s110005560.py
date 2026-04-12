import numpy as np
import sys

input = sys.stdin.readline

N = int(input())

print(N*800 - (N//15)*200)