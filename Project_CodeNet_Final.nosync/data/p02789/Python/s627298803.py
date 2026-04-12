#!/usr/bin/env python3
import numpy as np


DEBUG = True
dprint = print if DEBUG else lambda *x : x

N, M = [int(str) for str in input().strip().split()]

print('Yes' if N == M else 'No')