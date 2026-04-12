# -*- coding: utf-8 -*-

from queue import Queue
import sys
import subprocess
import json
import time
import math
import re
#import sqlite3
import random
import numpy as np
#from sklearn.datasets import fetch_mldata
from statistics import mean, median, variance, stdev
#from chainer import cuda, Variable, FunctionSet, optimizers
#import chainer.functions  as F

def ans():
    remain = X - Y - 2 * Z
    if (remain < 0): return 0
    res = 1
    while (remain >= Y + Z):
        remain -= Y + Z
        res += 1
    return res
    

X, Y, Z = map(int, input().split())
print(ans())
