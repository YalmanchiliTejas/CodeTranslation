import sys
import math
input = sys.stdin.readline
##

num_score = int(input().rstrip())
while num_score != 0:
    scores = []
    for _ in range(num_score):
        scores.append(int(input().rstrip()))
    total = sum(scores) - max(scores) - min(scores)
    average = math.floor(total / (len(scores) - 2))
    print(average)
    num_score = int(input().rstrip())

