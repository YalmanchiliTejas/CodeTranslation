can_see = 0
N = int(input())
H = map(int, input().split())
highest = 0
for i in H:
    if i >= highest:
        can_see += 1
        highest = i
print(can_see)
