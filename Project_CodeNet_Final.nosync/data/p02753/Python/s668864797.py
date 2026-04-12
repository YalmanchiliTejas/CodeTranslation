import sys
input = sys.stdin.readline

s = input()

if s.count('B') == 0 or s.count('A') == 0:
    print("No")
else:
    print("Yes")