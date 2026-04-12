from sys import stdin
n = int(stdin.readline().rstrip())
H = [int(_) for _ in stdin.readline().rstrip().split()]
count=0
for h in range(n):
    if h == 0:
        count+=1
    else:
        if H[h] >= max(H[:h]):
            count+=1
print(count)