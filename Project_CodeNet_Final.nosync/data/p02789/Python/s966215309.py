a = []
a = list(map(int, input().split()))

m = a.pop()
n = a.pop()

if m == n:
    print("Yes")
else:
    print("No")