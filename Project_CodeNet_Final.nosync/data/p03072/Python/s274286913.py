N = int(input())
H = [int(x) for x in input().split()]

print([all([x <= h for x in H[:i]]) for i, h in enumerate(H)].count(True))
