import sys
readline = sys.stdin.buffer.readline

s = readline().rstrip().decode('utf-8')

if "A" in s and "B" in s:
    print("Yes")
else:
    print("No")