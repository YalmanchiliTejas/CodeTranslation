import sys
input()
rows=[row for row in sys.stdin if '#' in row]
cols=[col for col in zip(*rows) if '#' in col]
for row in zip(*cols):print(*row, sep='')