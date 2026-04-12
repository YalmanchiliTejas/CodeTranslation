nl = lambda: list(map(int, input().split()))
sl = lambda: input().split()
n = lambda: int(input())
s = lambda: input()

X, Y, Z = nl()

print((X-Z) // (Y+Z))
