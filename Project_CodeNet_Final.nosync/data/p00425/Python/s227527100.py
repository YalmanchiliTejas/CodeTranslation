#!/usr/bin/env python
# -*- coding: utf-8 -*-

import copy

x = ['Front', 'Right', 'Back', 'Left']
y = ['Top', 'Front', 'Bottom', 'Back']
z = ['Top', 'Left', 'Bottom', 'Right']


def turn(dice, direction):
    turned_dice = copy.deepcopy(dice)
    # x?????????
    if direction == 'Right':
        for i in range(4):
            turned_dice[x[i]] = dice[x[(i+1)%4]]
    if direction == 'Left':
        for i in range(4):
            turned_dice[x[i]] = dice[x[(i-1)%4]]

    # y?????????
    if direction == 'North':
        for i in range(4):
            turned_dice[y[i]] = dice[y[(i+1)%4]]
    if direction == 'South':
        for i in range(4):
            turned_dice[y[i]] = dice[y[(i-1)%4]]

    # z?????????
    if direction == 'East':
        for i in range(4):
            turned_dice[z[i]] = dice[z[(i+1)%4]]
    if direction == 'West':
        for i in range(4):
            turned_dice[z[i]] = dice[z[(i-1)%4]]

    return turned_dice

if __name__ == '__main__':
    while True:
        n = int(input())
        if n == 0:
            break
        dice = {'Top': 1, 'Front': 2, 'Right': 3,
                'Left': 4, 'Back': 5, 'Bottom': 6}

        ret = 1
        for i in range(n):
            dice = turn(dice, input())
            ret += dice['Top']

        print(ret)