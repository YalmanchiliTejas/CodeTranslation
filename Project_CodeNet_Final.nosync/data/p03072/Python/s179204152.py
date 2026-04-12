n = int(input())
h_ary = [int(s) for s in input().split(' ')]

num = 0

for i, h in enumerate(h_ary):
    if max(h_ary[:i+1]) <= h:
        num += 1

print(num)