#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import math
import statistics


def get_average_score(scores):
    return math.floor(statistics.mean(sorted(scores)[1: -1]))


if __name__ == "__main__":
    while True:
        n = int(input())
        if n == 0:
            break
        else:
            print(get_average_score(int(input()) for i in range(n)))