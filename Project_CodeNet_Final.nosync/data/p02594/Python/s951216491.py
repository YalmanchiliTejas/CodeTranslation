import numpy as np
import math
import scipy as sp
import queue
import collections

MOD = 10 ** 9 + 7
INF = 10 ** 9

def main(kwargs):
    x = kwargs["x"]
    res = "No"
    if x >= 30:
        res = "Yes"
    return res

if __name__ == "__main__":
    kwargs = {}

    cin = input().split()
    kwargs["x"] = [int(i) for i in cin][0]

    cout = main(kwargs)
    print(cout)