def inpl(): return list(map(int, input().split()))

N = int(input())
P = input().split()

def calc(a, b):
    if a == "T" and b == "F":
        return "F"
    else:
        return "T"

a = P[0]
for b in P[1:]:
    a = calc(a, b)
print(a)
