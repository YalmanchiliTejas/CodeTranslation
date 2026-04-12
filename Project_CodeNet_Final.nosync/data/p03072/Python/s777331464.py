n = int(input())
h = list(map(int, input().split()))

tof = [True]*n

for i, val in enumerate(h):
    if i==0:
        continue
    if not val==max(h[:i+1]):
        tof[i] = False

print(sum(tof))

