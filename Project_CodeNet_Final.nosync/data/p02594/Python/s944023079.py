import sys
input = sys.stdin.readline
ins = lambda: input().rstrip()
ini = lambda: int(input().rstrip())
inm = lambda: map(int, input().split())
inl = lambda: tuple(map(int, input().split()))

n = ini()
print("Yes" if n >= 30 else "No")