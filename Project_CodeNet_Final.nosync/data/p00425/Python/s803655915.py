import math
import string
import itertools
import fractions
import heapq
import collections
import re
import array
import bisect

while(True):
    dice = [1, 2, 3, 4, 5, 6]
    score = 1
    n = int(input())
    if n == 0:
        break

    for i in range(n):
        action = input().rstrip()
        if action == "North":
            tmp = dice[0]
            dice[0] = dice[1]
            dice[1] = dice[5]
            dice[5] = dice[4]
            dice[4] = tmp
        elif action == "East":
            tmp = dice[0]
            dice[0] = dice[3]
            dice[3] = dice[5]
            dice[5] = dice[2]
            dice[2] = tmp
        elif action == "West":
            tmp = dice[0]
            dice[0] = dice[2]
            dice[2] = dice[5]
            dice[5] = dice[3]
            dice[3] = tmp
        elif action == "South":
            tmp = dice[0]
            dice[0] = dice[4]
            dice[4] = dice[5]
            dice[5] = dice[1]
            dice[1] = tmp
        elif action == "Right":
            tmp = dice[1]
            dice[1] = dice[2]
            dice[2] = dice[4]
            dice[4] = dice[3]
            dice[3] = tmp
        elif action == "Left":
            tmp = dice[1]
            dice[1] = dice[3]
            dice[3] = dice[4]
            dice[4] = dice[2]
            dice[2] = tmp
        score += dice[0]
    print(score)