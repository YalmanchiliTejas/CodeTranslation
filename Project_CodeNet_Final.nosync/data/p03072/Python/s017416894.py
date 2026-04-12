line = raw_input()
cases = int(line)

line = raw_input()
heights = list(map(int, line.split(' ')))

currentHeight = 0
cnt = 0
for H in heights:
    if currentHeight <= H:
        cnt += 1
    currentHeight = max(currentHeight, H)

print cnt