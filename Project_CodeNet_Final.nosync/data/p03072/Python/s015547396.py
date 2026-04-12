n = int(input())
h = [int(i) for i in input().split()]

t = -1
ans = 0

for i in h:
    if t <= i:
       ans += 1
       t = i

print(ans)