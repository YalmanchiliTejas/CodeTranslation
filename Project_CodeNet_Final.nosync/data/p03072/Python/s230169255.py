N = map(int, raw_input().split())
H = map(int, raw_input().split())

currentMax =H.pop(0)
total = 1

for i in H:
    if currentMax > i:
        continue
    currentMax = i
    total += 1

print total
