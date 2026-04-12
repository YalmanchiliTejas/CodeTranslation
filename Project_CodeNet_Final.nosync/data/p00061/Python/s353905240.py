# -*- coding: utf-8 -*-

import sys
import os

scores = [0]

for s in sys.stdin:
    p, s = map(int, s.split(','))
    if p == s == 0:
        break
    else:
        scores.append(s)

score_set = set(scores)
score_set = list(score_set)
score_set.sort(reverse=True)

for s in sys.stdin:
    n = int(s)

    teams_score = scores[n]
    print(score_set.index(teams_score) + 1)