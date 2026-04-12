import re
N = int(input())
H = [int(item) for item in re.split(r"\s", input())]

see = 1
for i in range(1, N):
    if max(H[:i]) <= H[i]:
        see += 1

print(see)
