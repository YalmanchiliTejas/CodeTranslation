from collections import Counter as mset

n = int(input())
inputs = []
for i in range(n):
    inputs.append(input())

intersection = mset(inputs.pop(0))

for w in inputs:
    intersection = mset(w) & intersection

print(''.join(sorted(list(intersection.elements()))))