"""
author : halo2halo
date : 2, Feb, 2020
"""

import sys
import itertools

import numpy as np

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

S = readline().decode('utf8').rstrip()
vowel = 'aiueo'

print('vowel' if S in vowel else 'consonant')
