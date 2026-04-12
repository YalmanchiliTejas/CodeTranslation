from sys import stdin
N = int(stdin.readline().rstrip())
H = map(int, stdin.readline().rstrip().split())
i = 0
high = 0
for h in H:
    if not(h < high):
        i+=1
        high = h
print(i)
