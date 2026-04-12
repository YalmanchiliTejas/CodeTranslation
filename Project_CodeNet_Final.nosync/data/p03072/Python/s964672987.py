N = int(input())
H = [int(i) for i in input().split()]

MAX = 0
count = 0

for X in H:
    if MAX <= X:
        MAX = X
        count += 1
print(count)
