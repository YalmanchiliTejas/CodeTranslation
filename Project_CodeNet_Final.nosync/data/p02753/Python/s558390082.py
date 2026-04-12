import sys
int1 = lambda x: int(x) - 1
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(500000)

S = read().decode().rstrip()

if S[0] == S[1] == S[2]:
    print("No")
else:
    print("Yes")
