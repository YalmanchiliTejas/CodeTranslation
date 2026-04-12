n = int(input())
a = list(map(int, input().split()))

M = 1000000007
A = sum(a)
A *= A
B = 0
for ai in a:
    B += ai * ai
print(int((A - B) // 2 % M))