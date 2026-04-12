from sys import stdin

s = stdin.readline().rstrip()
print("No" if (s == "AAA") or (s == "BBB") else "Yes")